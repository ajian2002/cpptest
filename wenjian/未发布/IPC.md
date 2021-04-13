# IPC

IPC 是 进程 间 通信（ interprocess communication） 的 简称。 传统上 该 术语 描述 的 是 运行 在某 个 操作系统 之上 的 不同 进程 间 各种 消息 传递（ message passing） 的 方式。

# IPC两种分类

## System-V-IPC

System V 消息 队列（ System V message queue， 第 6 章） 是在 20 世纪 80 年代 早期 加到 System V 内核 中的。 它们 可用 在 同一 主机 上有 亲缘 关系 或 无 亲缘 关系 的 进程 之间。 尽管 称呼 它们 时 仍 冠以“ System V” 前缀， 当今 多数 版本 的 Unix 却不 论 自己 是否 源自 System V 都 支持 它们。

```
 System V IPC:
 		System V 消息队列 		sys/msg.h
 		System V 信号量		sys/sem.h
 		System V 共享内存区	     sys/shm.h
```

![System-V-IPC](https://tu.yegetables.com/images/2021/04/12/System-V-IPC.png)

### System-V 小结



ipcs 输出信息

ipcrm 删除



msgget、 semget 和 shmget 这 三个 函数 的 第一个 参数 是 一个 System V IPC 键。 这些 键 通常 是 使用 系统 的 ftok 函数 从 某个 路径 名 创建 出 的。 键 还可以 是 IPC_ PRIVATE 这个 特殊 值。 这 三个 函数 创建 一个 新的 IPC 对象 或 打开 一个 已 存在 的 IPC 对象， 并 返回 一个 System V IPC 标识符： 接下 去 用于 给 其余 IPC 函数 标识 该 对象 的 一个 整数。 这些 整数 不是 特定 于 进程 的 标识符（ 像 描述 符 那样）， 而是 系统 范围 的 标识符。 这些 标识符 还 由 内核 在 一段时间 后 重用。

与 每个 System V IPC 对象 相 关联 的 是 一个 ipc_ perm 结构， 它 含有 诸 如属 主 的 用户 ID、 组 ID、 读写 权限 等 信息。 Posix IPC 和 System V IPC 的 差别 之一 是， 这些 信息 对于 System V IPC 对象 总是 可用 的（ 通过 以 IPC_ STAT 命令 参数 调用 三个 ctlXXX 函数 中的 某一个）， 但是 对于 Posix IPC 对象 来说， 能否 访问 这些 信息 要看 具体 实现。 如果 Posix IPC 对象 存放 在 文件 系统 中， 而且 我们 知道 它们 在 文件 系统 中的 名字， 那么 使用 现有 的 文件 系统 工具 就能 访 问到 与 ipc_ perm 结构 的 内容 相同 的 信息。 在 创建 一个 新的 System V IPC 对象 或 打开 一个 已 存在 的 对象 时， 可 给 getXXX 函数 指定 两个 标志（ IPC_ CREAT 和 IPC_ EXCL）， 外加 9 个 权限 位。 毫无疑问， 使用 System V IPC 的 最大 问题在于 多数 实现 在这 些 对象 的 大小 上 施加 了 人为 的 内核 限制， 这些 限制 可 追溯 到 它们 历史上 的 最初 实现。 这就是说， 较多 使用 System V IPC 的 多数 应用 需要 系统管理 员 修改 这些 内核 限制， 然而 不同 风格 的 Unix 完成 这些 修改 工作 的 步骤 也不 一样。

## Posix

Posix 是“ 可移 植 操作系统 接口”（ Portable Operating System Interface） 的 首 字母 缩写。 它 并不是 一个 单一 标准， 而是 一个 由 电气 与 电子 工程师 学会 即 IEEE 开发 的 一系列 标准。 Posix 标准 还 是由 ISO（ 国际 标准化 组织） 和 IEC（ 国际 电工 委员会） 采纳 的 国际 标准， 这 两个 组织 合称 为 ISO/ IEC。 Posix 标准 经历 了 以下 若干 代。

```
“ Posix IPC”：
			 Posix 消息队列	 	mqueue.h
			 Posix 信号量	         semaphore.h
			 Posix 共享内存区      sys/mman.h
```

![Posix-IPC](https://tu.yegetables.com/images/2021/04/12/Posix-IPC.png)### Posix小结

三种 类型 的 Posix IPC—— 消息 队列、 信号 量、 共享 内存 区—— 都是 用 路径 名 标识 的。 但是 这些 路径 名 既可以 是 文件 系统 中的 实际 路径 名， 也可以 不是， 而 这点 不一致 性 会 导致 一个 移植 性 问题。 全书 采用 的 解决 办法 是 使用 我们 自己的 px_ ipc_ name 函数。 当 创建 或 打开 一个 IPC 对象 时， 我们 指定 一组 类似于 open 函数 所用 的 标志。 创建 一个 新的 IPC 对象 时， 我们 必须 给 这个 新 对象 指定 访问 权限， 所 用的 是 同样 由 open 函数 使用 的 S_ xxx 常 值。 当 打开 一个 已 存在 的 IPC 对象 时， 所 执行 的 权限 测试 与 打开 一个 已 存在 的 文件 时 一样.




