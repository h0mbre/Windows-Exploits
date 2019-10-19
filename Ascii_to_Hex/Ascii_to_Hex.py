import textwrap
import binascii
import sys

function_name = sys.argv[1]

print textwrap.wrap((binascii.hexlify(function_name[::-1]).decode()), 8)
