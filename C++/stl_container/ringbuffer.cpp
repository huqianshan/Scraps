/*
 * @Author: gcfs-optane 1196455147@qq.com
 * @Date: 2024-03-12 20:05:13
 * @LastEditors: gcfs-optane 1196455147@qq.com
 * @LastEditTime: 2024-03-15 10:54:08
 * @FilePath: /Scraps/C++/stl_container/ringbuffer.cpp
 * @Description:
 */
#include <atomic>
#include <cstdint>
#include <memory>
#include <thread>
#include <vector>

using u64 = uint64_t;
template <typename T>
class CircleBuffer
{
    // https://github.com/cameron314/concurrentqueue
public:
    CircleBuffer(u64 max_size)
        : head_(0), tail_(0), size_(0), max_size_(max_size)
    {
        buffer_ = new T[max_size_];
    }
    ~CircleBuffer() {}

    bool Push(const T &item)
    {
        u64 current_size = size_.load();
        if (current_size == max_size_)
        {
            return false;
        }
        buffer_[head_] = item;
        u64 new_head = (head_ + 1) % max_size_;
        head_.exchange(new_head);
        size_.fetch_add(1);
        return true;
    }

    bool Pop(T &item)
    {
        u64 current_size = size_.load();
        if (current_size == 0)
        {
            return false;
        }
        item = buffer_[tail_];
        u64 new_tail = (tail_ + 1) % max_size_;
        tail_.exchange(new_tail);
        size_.fetch_sub(1);
        return true;
    }

    bool Front(T &item)
    {
        u64 current_size = size_.load();
        if (current_size == 0)
        {
            return false;
        }
        item = buffer_[head_];
        return true;
    }

    bool Back(T &item)
    {
        u64 current_size = size_.load();
        if (current_size == 0)
        {
            return false;
        }
        item = buffer_[tail_];
        return true;
    }

    bool IsEmpty() { return size_.load() == 0; }
    bool IsFull() { return size_.load() == max_size_; }
    u64 GetTail() { return tail_.load(); }
    u64 GetHead() { return head_.load(); }
    T At(u64 index) { return buffer_[index]; }
    u64 Size() { return size_.load(); }

private:
    const u64 max_size_;
    T *buffer_;
    std::atomic<u64> head_;
    std::atomic<u64> tail_;
    std::atomic<u64> size_;
};

// https://sf-zhou.github.io/programming/memory_barrier.html
template <typename T>
class LockFreeQueue
{
public:
    enum
    {
        kEmpty = 1,
        kFull = 2,
        kConflict = 3,
        kInvalid = 4,
    };

public:
    explicit LockFreeQueue(uint64_t capacity)
        : capacity_(capacity),
          items_(std::make_unique<std::unique_ptr<T>[]>(capacity)) {}

    uint64_t Size() const
    {
        auto t = tail_.load();
        auto h = head_.load();
        return h - t;
    }

    bool Empty() const { return Size() == 0; }

    bool Full() const { return Size() >= capacity_; }

    int PopByMutiThread(std::unique_ptr<T> *item, int retry_time = 5)
    {
        for (int i = 0; i < retry_time || retry_time == -1; i++)
        {
            uint64_t h = head_.load();
            uint64_t t = tail_.load();
            if (t == h)
            {
                return kEmpty;
            }
            if (items_[t % capacity_] == nullptr)
            {
                return kConflict;
            }
            if (tail_.compare_exchange_strong(t, t + 1))
            {
                auto &pop = items_[t % capacity_];
                if (pop == nullptr)
                {
                    return kConflict;
                }
                *item = std::move(pop);
                // tail_.fetch_add(1);
                return 0;
            }
        }

        return kInvalid;
    }

    int PopByOneThread(std::unique_ptr<T> *item)
    {
        auto t = tail_.load();
        auto h = head_.load();

        if (h == t)
        {
            return kEmpty;
        }

        auto &pop = items_[t % capacity_];
        if (pop == nullptr)
        {
            return kConflict;
        }
        *item = std::move(pop);

        tail_.fetch_add(1);
        return 0;
    }

    int PushByMultiThread(std::unique_ptr<T> *item, int retry_times = 5)
    {
        if (item->get() == nullptr)
        {
            return kInvalid;
        }
        for (int i = 0; i < retry_times || retry_times == -1; ++i)
        {
            auto t = tail_.load();
            auto h = head_.load();

            if (h - t >= capacity_)
            {
                return kFull;
            }

            if (head_.compare_exchange_strong(h, h + 1))
            {
                item->swap(items_[h % capacity_]);
                return 0;
            }
        }
        return kConflict;
    }

private:
    std::atomic<uint64_t> head_{0};
    std::atomic<uint64_t> tail_{0};

    const uint64_t capacity_;
    std::unique_ptr<std::unique_ptr<T>[]> items_;
};

int main()
{
    constexpr int N = 4;
    constexpr int M = 14;
    LockFreeQueue<int> queue(N);

    std::vector<std::thread> threads;
    for (int i = 0; i < M; ++i)
    {
        int value = i;
        threads.emplace_back([value, &queue]
                             {
                for (int j = 0; j < N; ++j) {
                    auto item = std::make_unique<int>(value* N + j);
                    // printf("push %d\n", value*N+j);
                    while (queue.PushByMultiThread(&item) != 0) {
                    }
                } });
    }

    std::unique_ptr<int> item;
    for (int i = 0; i < N * M; ++i)
    {
        while (queue.PopByOneThread(&item) != 0)
        {
        }
        printf("%d\n", *item);
    }

    for (auto &thread : threads)
    {
        thread.join();
    }
    return queue.Size();
}