### Configuring Snort

```wiki
var RULES_PATH rules/
portvar MY_PORTS [22,80,1024,8888]
ipvar MY_NET [192.168.1.0/24]
# ipvar EXAMPLE [1.1.1.1,2.2.2.0/24,![2.2.2.2,2.2.2.3]]
alert tcp any any -> $MY_NET $MY_PORTS (flags:S;msg:"SYN Packet";sid:1000)
include $RULE_PATH/example.rules
```

### Preprocessors[^1]

`preprocessor  <name> : <options>`

```
preprocessor frag3_global: prealloc_nodes 8192
preprocessor frag3_engine: policy linux bind_to 192.168.1.0/24
```



---

[^1]: 预处理器允许用户相当容易地将模块化插件放入Snort，从而扩展了Snort的功能；预处理器代码在调用检测引擎之前运行，但在数据包解码之后运行