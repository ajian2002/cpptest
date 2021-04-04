import base64
contents=b"asdsafafsdg213125w4tww46568AS"
s=base64.b64encode(contents)
print(s) # b'YXNkc2FmYWZzZGcyMTMxMjV3NHR3dzQ2NTY4QVM='
print(base64.b64decode(s)) # b'asdsafafsdg213125w4tww46568AS'
