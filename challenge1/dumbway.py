"""Convert Hex string to Base64"""
import base64

HEX_STRING = '49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d'

BYTE_ARRAY = bytearray.fromhex(HEX_STRING)
BASE64_VAL = base64.b64encode(BYTE_ARRAY)
print(BASE64_VAL)