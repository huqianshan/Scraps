#/bin/bash/

# https://developer.work.weixin.qq.com/document/path/91770

generate_post_data() {
    cat <<EOF
{
    "msgtype": "text",
    "text": {
        "content": "hello world"
    }
}
EOF
}

url="https://qyapi.weixin.qq.com/cgi-bin/webhook/send?key=30d304e1-4442-408a-948f-e3e4a4725e98"
type='Content-Type: application/json'
curl ${url} -H ${type} -d "$(generate_post_data)"
