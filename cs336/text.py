print("this is" + chr(0))
test_string = "hello! 世界"
utf8_encoded = test_string.encode("utf-8")
print("***this is utf8encode***\n",utf8_encoded)
#print(list(utf8_encoded))
#print(type(utf8_encoded))
print("the length of test_string",len(test_string))
print("the length of utf8_encoded",len(utf8_encoded))
#print(utf8_encoded.decode())

utf16_encoded = test_string.encode("utf-16")
print("***this is utf16_encode***\n",utf16_encoded)
print("the length of test_string",len(test_string))
print("the length of utf16_encoded",len(utf16_encoded))

utf32_encoded = test_string.encode("utf-32")
print("***this is utf32_encode***\n",utf32_encoded)
print("the length of test_string",len(test_string))
print("the length of utf32_encoded",len(utf32_encoded))

def decode_utf8_bytes_to_str_wrong(bytestring: bytes):
    return "".join([bytes([b]).decode("utf-8") for b in bytestring])
#这段代码是错的，这个具体来说是把bytestring里面每个byte 提出来decode
#这对于英文(一个byte表示一个字母)当然没错，但是对于中文(三个byte表示一个字符),这一定会报错

print(decode_utf8_bytes_to_str_wrong("hello".encode("utf-8")))