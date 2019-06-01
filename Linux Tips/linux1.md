### kali2.0上python的设置切换默认版本

```bash
update-alternatives --install /usr/bin/python python /usr/bin/python2 100
update-alternatives --install /usr/bin/python python /usr/bin/python3 150
# 切换Python版本
update-alternatives --config python
# 查看目前使用的Python版本
python --version
```

