# Handler
Handler��CoreLooper��ܹ���Ļ�������������Android�е�Handler,MFC�е�CWnd��win32�е�HWND
Handler����ʹ��timer,��ͬһlooper�Ϳ�looper sendMessage����postMessage,�충����Handler����Ϣ

### Handler��������

![img](images/handler.lifecycle.png)

<div style='display: none'>
ͼƬ���ɷ���:
https://mermaidjs.github.io/mermaid-live-editor
graph TD
A("Begin") -->|"����make_shared< Handler>()����Handler" |Start(Handler���캯��)
Start -->|Handler.Create����parent.AddChild,�󶨵�Looper| B(Handler::OnCreate)
B -->|Destroy| C(Handler::OnDestroy)
C -->|"���һ��ǿ������ʧʱ"| D(Handler �������� )
D --> End(End)
</div>


#### ����Handler
��������ʽ������Handler,
- ��һ����c++���Բ����ϵĴ���,��new����
  Handler������heap�д�����������stack�д���
  ǿ�ҽ������make_shared������c++���󣬲�Ҫֱ�ӵ���new,һ��newҲ��Ҫ��Ҳ��Ҫ����delete,����ȫ������smart pointer������

- �ڶ����ǿ�ܲ����ϵĴ���,���󶨵�Looper������parent/child��ϵ
 Handlerֻ����Looper�����´���,���ұ���󶨵�Looper���������ʹ��
��ܽӿ�����
```cpp
virtual void LOOPER_SAFE Create(shared_ptr<Handler> parent);
virtual int LOOPER_SAFE AddChild(std::weak_ptr<Handler> child, std::string name = "");
```
�����¼��ֵ����÷�
```cpp
auto obj=make_shared<Handler>();
//��ʱHandler��û�а󶨵�Looper,����Handler������ߴ˴�����ʼ������
obj.Create(parent);
```
���߸���һ�㣬�ڲ���Ҫ��ʼ��ʱ
```cpp
parent.AddChild(make_shared<Handler>());
```
������ڸ����е���(һ�����ڸ���.OnCreate)������Լ�Ϊ
```cpp
AddChild(make_shared<Handler>());
```
˵��:
- Handler֧�ֿ�looper����,������MainLooper�д���HandlerȻ��󶨵�WorkLooper��
- ֻ�а󶨵�Looper֮��,handler����ʹ�ÿ���ṩ�Ĺ��ܣ�����timer,sendMessage,postMessage��


#### ����Handler
```cpp
virtual void LOOPER_SAFE Destroy();
```
����Handler.Destroy()������Handler,����Handler�󶨵�Looper�е���OnDestroy()
app���Զ�ε���Handler.Destroy()����������������Ӱ�죬�ɿ�ܱ�֤OnDestroy()�ᱻ���ò���ֻ������һ��

���ٺ������ǲ�ͬ�ĸ���
�����Ǳ���ܶ���ģ�������c++���Զ����

˵��:
- ���ٲ�Ӱ��timer,sendMessage��postMessage�ȹ��ܣ���Щ���������ٺ���Ȼ����
- ���ٺ��Handler�����ٴ�Create����AddChild
- parent����ʱ���Զ��ݹ����������е�child,��������
- parent������ʱ�����������AddChild,��ʱchild�������������������Զ�����

#### ����
��Handler�����һ��shared_ptrʧЧʱ���������

##### Handler�����������ĸ�Looper������
- ���ֻ�ڰ󶨵�Looper��ʹ��Handler,����ڴ�Looper������Handler
- �����Looperʹ����һLooper�е�shared_ptr< Handler>,������Handler.Destroy()����Ȼ���ִ�shared_ptr,���кܵ͵ļ��ʿ�Looper����Handler
##### ��Looper����Handler���ͽ���취
������Handler.Destroy()��,��ԭ��Looper����һ��shared_ptr< Handler>���ӵ�gc(��������)�������ϼ����ա�
���⣬��gc�б�����ĿʱLooper�ᶨʱ�����ա�

�����㷨����
1. ����weak_ptr���ô�Handler
2. ���shared_ptr< Handler>
3. ��weak_ptr����lock(),���Ϊnullptr,˵��Handler������;�����Ϊnullptr,˵�����������,HandlerҪ���¼ӵ�gc�б�

�ٶ�:
LooperA��gc��������HandlerA,
 LooperB��shared_ptrҲ������HandlerA
��LooperA�����������2��,����û���е�3����
��ʱ��LooperB����������õ�shared_ptr< HandlerA>,�����LooperB������HandlerA

���ܼ��ʺ�С����������ڿ�ܲ����c++���Բ��涼û��������
��õĽ���취����app��֤�Զ����Handler������֧�ֿ�looper������
��ܱ����Hanlder�ǿ�Looper������ȫ�ġ�

 ����: ** todo ** ���Ҫ�ṩ�ӿ�������app���Կ�Looper����Handler�����Ӱ�ȫ�ԡ�

#####  �����ܽ�
��ܻ����ɱ�֤�ڰ󶨵�Looper������Handler(�����������)
��ܱ�֤Handler�������looper�����ǰ�ȫ��,app�Զ����Handler����ֻ����app���б�֤
����취�ܼ�,Handler.OnDestroy()ʼ�����ڰ󶨵�Looper�е��õ�,Handler����ֻ��Ҫ��OnDestroy()�������ɡ�



### ��ʱ�� Timer
``` cpp
	virtual long SetTimer(long& timerId, UINT interval);
	virtual long KillTimer(long& timerId);
	virtual void OnTimer(long timerId);
```

����ڲ�����ʱ���ֹ���timer
���������ٺʹ���timer�ĸ��Ӷȿ���Ϊ��O(1),�����ɹ��������timer

#### SetTimer
�ڵ���Handler.Create����.AddChild����Handler֮�󣬾Ϳ��Ե���SetTimer��������ʱ��
����:
- timerId:����&�������,0Ϊ��Чֵ,�������0��timerIdʱ,SetTimer�������ٴ�timer,�ٴ����������µ�timerId
- intervalΪ�����������ʾ���ʱ�䣬��λ:����,��С����Ϊ1ms,��0ʱ��Ĭ��ȡ1ms,ʵ�ʴ���OnTimer�ľ���ȡ����OS

#### KillTimer
��������Ҫ��ʱ��ʱ���ɵ���KillTimer������

Timer�Ĳ���˵��:
- ��Handler����ʱ���Զ����ٴ�Handler���������ж�ʱ��
- Handler.Destroy()��Ӱ��timer

