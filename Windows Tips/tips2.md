### Windows设置电脑允许或拒绝远程桌面连接

- `sysdm.cpl(系统属性)` → 远程 → 远程桌面
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

### 查看系统属于的域

`sysdm.cpl`→ 计算机名 → 更改 → 隶属于

### 查询域

```powershell
ipconfig /all
net view
net view /domain #查询有几个域
net group /domain #查询域里面的组
net user /domain #查询域用户
net group "domain admins" /domain #查询域管理用户组
```

### 端口转发工具 [^1]

`netsh`

 [netsh.md](..\Doc\netsh.md) 

### Windows软件管理器

- Scoop

```powershell
# powershell
set-executionpolicy remotesigned -scope currentuser 
iex (new-object net.webclient).downloadstring('https://get.scoop.sh') # 安装scoop
scoop help
scoop search nmap
scoop install grep
scoop install netcat
scoop list
```





---

[^1]: vIDC、lcx、netsh (Windows自带)