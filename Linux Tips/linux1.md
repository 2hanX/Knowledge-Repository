### kali2.0上python的设置切换默认版本

```bash
update-alternatives --install /usr/bin/python python /usr/bin/python2 100
update-alternatives --install /usr/bin/python python /usr/bin/python3 150
# 切换Python版本
update-alternatives --config python
# 查看目前使用的Python版本
python --version
```

### 查看Linux系统版本信息

#### 看Linux内核版本命令

- `cat /proc/version`
- `uname -a`

#### 查看Linux系统版本的命令

- `lsb_release -a`
- `cat /etc/issue`

### 删除旧文件和缓存文件

```shell
sudo apt-get autoclean //清理旧版本的软件缓存
sudo apt-get clean //清理所有软件
sudo apt-get autoremove //删除系统不再使用的孤立软件
```

### 插入数据到文件指定行数[^1]

`sed -i 'ni\xx' target.file`

`sed -i 'na\xx' target.file`

`sed -i '2i\hello' demo.txt`

`sed -i '4a\hello world' demo.txt`

### 使用Base64 加解密

`echo hello | tr -d '\n' | base64` [^2]

`echo -n hello | openssl base64`

`echo aGVsbG8= | base64 -d `

`openssl base64 -d -in file.txt` [^3]

### 其他加密 [^4]

`echo -n abcd | openssl sha1 `

`echo -n abcd | openssl aes-128-cbc -k 123 -base64`



---

[^1]: ==i==（in front，前面）；==a==（after，后面）
[^2]: 在进行 Base64 加密前去掉换行符，或者`echo -n hello | base64`
[^3]: 对`file.txt`文件进行 base64 解密；或者 `cat file.txt | base64 -d`
[^4]: 更多OpenSSL支持的加密算法`man openssl`

