## ioctl.py
Quick script to decode I/O control values for Windows drivers:
+ Determine Device Type,
+ Determine Access Check,
+ Determine Function Code,
+ Determine I/O Method, and
+ Output `CTL_CODE` macro template (if possible).

## Usage
`Usage: example.py <ioctl code>`

`Usage: example.py 0x222003`

## Output
```terminal_session
root@kali:~# ./ioctl.py 0x2222CE                                      
[*] Device Type: FILE_DEVICE_UNKNOWN
[*] Function Code: 0x8b3
[*] Access Check: FILE_ANY_ACCESS
[*] I/O Method: METHOD_OUT_DIRECT
[*] CTL_CODE(FILE_DEVICE_UNKNOWN, 0x8b3, METHOD_OUT_DIRECT, FILE_ANY_ACCESS)
```


## Notes
Harcoded dictionary values come from: `ntddk.h`, `devioctl.h`, and `irclass_ioctl.h`. 

Inspired by the OSR online tool: https://www.osronline.com/article.cfm%5earticle=229.htm

Created with help from: https://social.technet.microsoft.com/wiki/contents/articles/24653.decoding-io-control-codes-ioctl-fsctl-and-deviceiocodes-with-table-of-known-values.aspx

***Could have bugs, only tested 3 IOCTLs.***
