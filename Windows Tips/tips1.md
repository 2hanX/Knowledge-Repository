### 使用windows 命令行创建一个空的文本文件

1. 使用 `fsutil `创建一个文件大小为3000比特的文本

   `fsutil file createNew C:\Desktop > 2.txt 3000`

2. 使用 `echo `创建一个文本

   `echo > demo.txt`

3. 使用 `type` 创建一个文本

   `type nul > 4.txt`

### 使用windows 命令行查看文件内容

1. `type demo.txt`
2. `type demo.txt | findstr hello`

### 使用windows 命令行强制终止进程

- `taskkill /pid 1230 /f`

### 修改Windows服务的描述

- `sc description "Tenable Nessus" "这是Nessus服务的描述字段"`

### 根据进程名称查找进程

- `tasklist | findstr explorer*`
- `tasklist /fi "imagename eq explor*"`

### 根据进程 ID 查找进程

- `tasklist /fi "pid eq 10120"`

### 查看进程使用的 DLL

- `tasklist /fi "pid eq 10120" /m`

### 根据进程 ID 查看该进程的 tcp 网络连接

- `netstat -anop tcp | findstr 10120`

### 命令行打开计算机管理面板

- `compmgmt.msc`

### 命令行打开远程桌面程序

- `mstsc`

