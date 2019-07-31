### 文件格式头[^1]

| 文件类型 | 文件头标识（HEX）            | 开头   | 结尾    |
| -------- | ---------------------------- | ------ | ------- |
| PNG      | `89 50 4E 47 0D 0A 1A 0A`    | PNG    | IEND    |
| RAR      | `52 61 72 21`                | RAR    |         |
| JPG;JPEG | `FF D8 FF FE 00 4A 46 49 46` | JFIF   | `FF D9` |
|          | `47 49 46 38 39 61`          | GIF89a | `3B`    |

### 使用 `certutil `工具校验文件

```
certutil -hashfile file MD5
certutil -hashfile file SHA1
certutil -hashfile file SHA256
```

### 查看磁盘信息

- `diskmgmt.msc`
- `diskpart`→`list disk`

---

[^1]: 格式不完全相同，但开始几个字节是固定值；例如 GIF89a 与 GIF87a