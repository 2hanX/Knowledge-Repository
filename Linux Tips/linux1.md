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

