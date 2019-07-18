### 测试安装是否成功

`> tex --version`

### 示例

```powershell
> latex sample2e.tex #处理一个基本的 LATEX 文件
> dviout sample2e.dvi # Windows 即时预览结果
> pdflatex sample2e.tex # 创建 PDF 文件而非 DVI，这里采用直接处理 .tex 文件输出 PDF 的方式
```

### tlmgr: 管理你的安装[^1]

```powershell
> tlmgr -gui
> tlshell -gui
> tlmgr update -list
> tlmgr update -all # 更新系统
```

### 帮助文档

- [tug.org](http://tug.org/begin.html)
- [在线(La)TeX文档](http://tug.org/interest.html#doc)



---

[^1]: 以用来管理安装后的系统。它的功能包括： 1. 列出方案 (scheme)，集合和安装包； 2. 安装、升级、备份、恢复、卸载软件包，并且能自动计算依赖关系； 3.  查找和列出软件包以及它们的描述； 4. 列出、添加和删除不同平台的可执行文件； 5. 改变安装选项等