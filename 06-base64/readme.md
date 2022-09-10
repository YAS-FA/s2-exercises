# Base64 Encoder/Decoder
Write a Base64 file encoder and decoder. In decoder mode if input is not a valid `base64` text, your application should display error with proper return code.

Base64: https://en.wikipedia.org/wiki/Base64


## User Interface

```
$ base64 [enc/dec] SRC_FILE DST_FILE
```



## Examples


`input.txt`:
```
Hello World!!
```

```
$ base64 enc input.txt output.b64
```

`output.b64`:
```
SGVsbG8gV29ybGQhIQ==
```

```
$ base64 dec output.b64 output.txt
```

`output.txt`
```
Hello World!!
```

```
$ base64 dec invalid_file.b64 output.txt
Error: Invalid base64 input
```