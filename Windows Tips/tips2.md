### Windows设置电脑允许或拒绝远程桌面连接

- `sysdm.cpl(系统属性)` -> 远程 -> 远程桌面
- `rdesktop -u test$ -p 123456 192.168.1.1 -r sound:on -g 1024*768`

### cmd 下查看系统环境变量

- `echo %path%`
- `echo %date%`
- `echo %os%`
- `echo %username%`
- `set os`
- `set username`

### cmd下使用 `set` 和`certutil`对字段进行 base64 加密

```commonlisp
# 避免使用 `echo` 输入，因为它默认在末尾有换行
set /p = "hello world" <nul > a.txt
certutil -encode a.txt b.txt
type b.txt
notepad b.txt
```

### 获取本地外网IP地址

`curl cip.cc`

