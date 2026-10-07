PAT = r"""'(?:[sdmt]|ll|ve|re)| ?\p{L}+| ?\p{N}+| ?[^\s\p{L}\p{N}]+|\s+(?!\S)|\s+"""
#神秘正则表达式拆解字符串

import regex as re
a = re.findall(PAT,"some text that i'll pre-tokenize")
print(a)