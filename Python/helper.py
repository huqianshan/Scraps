# %% 输出当前文件夹中文件

from PyPDF2 import PdfFileReader, PdfFileWriter
import os

file_list = [file for file in os.listdir(file_dir)]

# %% PDF处理函数，向pdf中插入指定pdf
for file in file_list:
    output = PdfFileWriter()
    t = open(file_dir+"\\"+file, "rb")
    pdf_file = PdfFileReader(t)
    output.addPage(pdf_file.getPage(THEPAGE))
    outputStream = open(write_dir+"\\"+file, "wb")
    output.write(outputStream)
    outputStream.close()
    t.close()
    print(f"write {file} success ")
