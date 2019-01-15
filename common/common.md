### 通用定义

1. json协议根目录

```
/luajson
```

2. Key字段字符集

```
* 字母[a-zA-Z]
* 数字[0-9]
* 下划线[_]
* 必须以字母开头
* 不区分大小写
* 不支持其他任何特殊符号,便于通用于任何语言解析json并使用
```

3. 命名约定

```
* 同一次请求,重复协议命令情况下,追加后缀"_N[N.]",N=[0-9],
* 协议命令注意规避末尾带"_N[N.]"
```

4. 协议区分

```
请求必须带字段 cmd,llssid,llauth
回复必须带字段 cmd

注意：
* 客户端向服务端获取数据协议不带"get_*"前缀,默认下全部为获取数据
* 客户端向服务端设置协议带"set_*"前缀
* 客户端向服务端控制协议带"ctrl_*"前缀
* 媒体相关业务协议带"open_*","close_*"前缀
* 服务端向客户端主动推送协议带"push_*"前缀
```

* 注意事项

```
* 客户端向服务发送的数据量限制为1M
* 服务端向客户端发送的数据限制为4M
```