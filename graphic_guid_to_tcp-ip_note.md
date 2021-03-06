##第一章
1. 分组交换： 将大数据分割为一个个叫做包的较小单位进行传输.
2. 协议分层：同一层之间的交互所遵循的约定叫做"协议",上下层之间进行交互时所遵循的约定叫做"接口"
3. OSI参考模型: 应用层;表示层;会话层;传输层;网络层;数据链路层;物理层
4. 电路交换:建立连接以后，独占线路进行数据传输
5. MAC寻址：地址转发表  IP寻址：路由控制表
6. 网关/4-7层交换机/路由器/网桥/中继器

##第二章TCP/IP基础知识
1. TCP/IP模型：物理层/数据链路层/网络层/传输层/应用层
2. 网络层
	1. IP协议:不具有重发机制，非可靠传输协议
	2. ICMP:无法发送到对端目标地址时，给发送端发送一个发生异常的通知
	3. ARP:从分组数据的IP地址中解析出物理地址(MAC地址)
3. 传输层
	1. TCP
	2. UDP
4. 应用层:相当于集中了OSI模型的会话表示和应用层
	WWW:HTTP  E-Mail:SMTP  FTP TELNET SSH SNMP

##第三章数据链路
1. 共享介质型网络
	1. 基本上采用半双工
	2. 介质访问控制方式:
		*  争用型:CSMA(载波监听多路访问);CSMA/CD
		* 令牌传递方式
2. 非共享介质型
很多采用全双工方式(允许同一时间发送和接受数据);通过以太网交换机构建网络
3. 以太网交换机根据转发表转发，自学得到;根据MAC地址转发
4. 环路检测技术:1 生成树法;2 源路由法(RIF)
5. 以太网;以太网帧格式
6. 无线网络:IEEE802.11定义了LAN协议中物理层与数据链路层的一部分
7. PPP 点对点

##第四章IP协议
1. IP寻址;路由;IP分包与组包
2. IP属于面向无连接型
3. IP地址由网络地址和主机地址形成;A,B,C,D类地址;主机地址不能全为0或者1;主机地址全为1表示广播地址;
4. IP多播用于将包发送给特定组内的所有主机,可以穿透路由器;多播使用D类地址
5. 地址分类不再使用，而用子网掩码的方式
6. 全局地址与私有地址:私有地址通过NAT通信
7. 路由控制:
	1. 路由控制表;
	2. 默认路由，主机路由，环回地址;
	3. 路由控制表的聚合(减少路由表的条目)
8. IP分割处理与再构成处理:
	1. 大于MTU时要进行分片;
	2. 路由器分片，目标主机进行重组;
	3. 路径MTU发现：找所有数据链路中最小的MTU，在发送主机上进行分片; 利	       用ICMP获得MTU;UDP是在IP层负责分片，TCP是TCP负责拆分数据
9. IPv6:
	1. 全局单播地址:64网络标识+64位主机标识;链路本地单播地址;唯一本地地址
10. IPv4首部

##第5章IP协议相关技术
1. DNS:域名服务器;DNS如同互联网中的分布式数据库
2. ARP:只适用于IPv4;关联IP地址与MAC;RARP:从MAC地址定位IP地址的一种协议
3. ICMP: 
	1. 确认IP包是否发送成功，通知在发送过程中IP包被丢弃的具体原因，改善网络设置等; 
	2. 主要消息:目标不可达消息;重定向消息;超时消息:TTL;回送消息;
	3. ICMPv6: IPv6正常通信必须;邻居探索:融合了ARP,ICMP重定向，ICMP路由器选择消息等功能
4. DHCP实现即插即用:DHCP服务器;DHCP中继代理
5. NAT:使用私有地址在连接互联网时转换成全局IP地址的技术;NAT-PT:将IPv6首部转换为IPv4首部的一种技术
6. IP隧道 
