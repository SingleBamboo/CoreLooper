# todo 
 ����ĵ���Ҫ��̫��ϸ�ڣ�����Ѷ�������
 ϸ����������ĵ��н�����������Ȥ���û������о�
# CoreLooper���
CoreLooper��һ������c++11��ͨ��������,֧��ͨ��ҵ�������ͨѶ��

- �����ʲô
����˵,�����һ�׿���չ�������õ���������һ����Ϊ�˼򻯺͹淶ĳһ����������������ơ�
��ܿɷ�Ϊͨ�ÿ�ܺ�ר�ÿ�ܡ�
ͨ�ÿ�ܲ���Ծ����ҵ��һ��ֻʵ��������Ĺ��ܣ��������ںܶೡ�ϡ�
ר�ÿ��������רע��ĳ��ϸ����������Ժ�ǿ��
������ͨ�ÿ�ܵĻ����Ϲ���ר�ÿ�ܡ�
- ʹ�ÿ����ʲô�ô�
��һ�仰�Ϳ��Խ����:��ܴ�������ͨ��ϸ�����⣬���û����о�������Ӧ�ò�ҵ��

## CoreLooper��Ҫ�ص�
��Դ���Ѿ����ڶ�������,����ace,asio,evpp,libevent,libuv,libev,muduo,��CoreLooper�����ڲ�ͬ�ĵط�
- �ṩͨ���걸�Ļ�����ʩ������������������Ӧ��
- ������������, ������c++11(ֻ�õ�shared_ptr,weak_ptr,auto������c++11����)
- ֧��Android, iOS, Linux, Windows(x86/x64),����ֲ������ƽ̨
- ����������չ��
 ���������ʵ���������ģʽ,������java���ʵ��java��Դ��Ĺ��ܣ�����netty,eventbus,spring��
- ����˶�ƽ̨֧�ֵ�����
  CoreLooper������ƽ̨���ṩͳһ�Ľӿڣ��û�����Ҫ����ÿ��ƽ̨��ϸ��
- �����thread����̫�󲻺ÿ��Ƶ�����
   ���ں���������ǵ��̵߳ģ�Ϊ�˸�ϵͳ���ṩ�˴����̵߳Ľӿڣ�����������c++���棬����ӿڹ��ڼ�ª����pthread_createΪ��,��ֻ��Ҫ�ṩһ���߳���ں���ThreadFunc���������Ƚ��ʺ�һ�����ܵ�ͷ������ʵ�ʵ�ҵ���У��߳̾�����Ҫ�������߳̽���
- �����������߳�ͨѶ����
 ͨ��sendMessage��postMessage,����߳��е�����ɻ��෢����Ϣ��ȫͨѶ 
- ����������Ҫ�������ܱ�֤�̰߳�ȫ������
 �ڶ��߳�Ӧ���У���ͬ�߳��е����������Ҫ������ã�Ϊ�˱�֤�̰߳�ȫ��������Ҫ����ͬ����������һ���appԴ���п��Կ��������ļ������á�
����ʵ��һ�������ص����⣬��ҵ����ʱ��һ����������ȫ�����ã��������������������������ҵ����Ų�Ƚ����ѣ�һ�����������������ġ�
CoreLooper��ȫ��������һ���������������Ҫ���м�����һ����Ҳ��Ҫ������ʵ�ֿ��̰߳�ȫͨѶ��
- ������������ȫ�Զ������������ֹ�������ͷ��ڴ�
 �����ʵ��c++11����ָ�����ģ�֮����������ǿ��������ΪĿǰ���������Դ�����û���õ�����ָ�룬��Ȼ�ǲ����ֹ������������ܶ����⡣CoreLooper��ܴ��ģӦ��������ָ�룬����֤����Ч���ܺã������ڴ�ǿ���Ƽ�
- ���ӻ���̣������˵����Ų�app�������Ч��
����˵�Ŀ��ӻ�����ָ������VS,AndroidStudio���������� UI����,������ʵʱ�鿴���������״̬���ݡ�
�ڿ��������У�������Ҫ����־������������,��ӡ���˻�����������ܵĵ��ڣ���ӡ������ʱ�뿴�ı���û��ӡ������Ҫ�޸Ĵ��룬���±����ٲ��ԣ���ʱ�����������֡�
Ϊ�˽���������,BaseLooper�����õ�HTTP��������������һ������չ��ajax��ܡ������ô˿�����鿴���޸����ݣ�������������һ��proc.xml�ӿڣ�����ͨ����������鿴�����ʵʱ�ڲ�״̬,�ܰ���������Ա���ٶ�λbug��
## CoreLooper�ر��ע������֪�����翪Դ���һЩʹ��
- muduo
 
- evpp
 evpp readme����һ�λ�����ӡ�����,��: https://github.com/Qihoo360/evpp/blob/master/readme_cn.md
 ժ������:
> ����ʵ�ֹ����м��������̰߳�ȫ���⣬һ���¼���ص���Դ��������������`EventLoop`��ÿ��`EventLoop`��һ���̣߳��г�ʼ���������ͷţ���������������޶ȵļ��ٳ���Ŀ��ܡ�Ϊ�˴ﵽ���Ŀ����������`event_add`��`event_del`�Ⱥ�����ÿһ�ε���`event_add`�����ڶ�Ӧ���߳�˽�������м�¼�ö����ڵ���`event_del`ʱ�����֮ǰ���߳�˽���������Ƿ�ӵ�иö���Ȼ�������������˳�ǰ���������ļ�������̵߳�˽�����ݣ������Ƿ���Ȼ�ж���û�������ͷš�����ʵ������������ϸ����ʵ�ֿ��Բο� [https://github.com/Qihoo360/evpp/blob/master/evpp/inner_pre.cc#L36~L87](https://github.com/Qihoo360/evpp/blob/master/evpp/inner_pre.cc#L36~L87)��������˿��̵�׷���̰߳�ȫ��ֻ��Ϊ����һ��������**������ƽ�ȵ��˳���Reload**����Ϊ������̵���⡰��д��Զ���е�ϵͳ���ͱ�д����һ��ʱ���ƽ���رյ�ϵͳ�������¡�������Ҫ���ѵĶ�öࡣ

Handler��Looper������evpp�������������,CoreLooper��Handler����û�������,
���app�̳�Handlerʱ�����˿�Looper�������⣬��Ҫ��app���н��

 
##  CoreLooper������ʲô
- ����������
CoreLooper���������������ܷ���������֧��TCP,UDP������Э��,�����û������йҿ������źŻ��Ƶ���ܡ�
������֪��ʱ���Է�������˵�Ǳز����ٵģ�����CoreLooper�����˶Ը����ܶ�ʱ����֧�֣����ڴ��������ٺ͵��ȶ�ʱ����ʱ�临�Ӷȶ���O(1),�����ں����ͻ������ӵ�ҵ����

- ������������ҵ�豸��
CoreLooper�ѱ���ֲ����˼IPC����,����IPC����, MTK6572���豸��,֧��intel x86/x64,arm32/64,mips��оƬƽ̨��

- �����ͻ���
CoreLooper����������Android, ios, linux��Windows�ȿͻ���
�������ϵͳ�Դ�UI���,�漰�����ҵ��ɲ���CoreLooper������
�����ĺô���ҵ���ֻ��Ҫ��һ�Σ�����ͨ��������ϵͳƽ̨,����ʡ����ʱ��ͳɱ���

- ������ƷSDK
�ںܶ�����£���˾����Ӳ����Ʒ����Ҫ�ṩSDK�������ͻ�ʹ��,��ЩSDKһ��ҲҪ֧�ֶ��ϵͳ������������򵥣�ʵ��������ȴ�������ܶ����⡣
�ٸ��򵥵����ӣ�Ҫ��һ��SDK,��SDKҪ�ṩ�ӿ���ͨ�������������豸��Ȼ������صĲ�������һ��ǰ����SDKҪ�����������û�ʹ�÷��㣬���û�һ��������UI�߳���ֱ�ӵ���SDK�ӿڣ����Ҫ��SDK�ӿڶ�Ҫ���ɷ������ġ�������ŵ��ṩ�ӿ���ʵ��������ܣ�����һ���ѶȺ͹������ġ�
CoreLooper������ǻ�����������������,��һ��ʼ�Ϳ��ǵ�����Ӧ�ã������涼�����˺ܶ�ϸ�����Ⲣ��������ˡ�
- ����ActiveX/OCX�ؼ�
 �����ִ������������֧��OCX�ؼ��ˣ��ϵ�IE�����Ȼ֧�ִ������CoreLooper����
- ��������Ӧ��(����RS232,RS485)
 CoreLooper�Ѽ��ɴ��ڹ���,ʵ����ֻҪ����iocp,epoll��kevent�����Ĺ��ܶ��ɷ���ļ��ɵ�CoreLooper�����
- ��������ͨ�ÿ�
 CoreLooper�ṩ���ڶ�������ܣ����ڴ˻����Ϲ������Լ��Ŀ�
- ����Ӧ�ó���
 ֻҪ֧��c++11���Ϳ���ʹ��CoreLooper���


## CoreLooper������ʲô
- CoreLooper���Ժ�UI�����ʹ�ã���ĿǰCoreLooper����ֱ����UI����
 ������ϵͳ��ԭ��UI���Ѿ������㹻���ˡ�
- CoreLooper��ע����ҵ���߼��㣬��Ҫ��������ͨѶ��ϵͳ������Ŀ��߳̽����ȡ�
- ���������:ϵͳԭ��UI�㸺�����չʾ,CoreLooper����ҵ������紦��
- ��������DirectUI,�����п�Դ���Ƶ�UI��, �о�Ҳ�ǿ��Լ��ɵ�CoreLooper�е�,����Ҫ�����Ŀ�,���缯��Ϊlibdui,��QQ,TIM�Ľ���Ӧ�þ�����DUI����.
 ֵ��һ�����github���и�opengl/DirectX��UI����Ŀimgui(https://github.com/ocornut/imgui),�о�Ҳ�ܼ��ɵ�CoreLooper����opengl/DirectX��UI���Կ�ƽ̨��������Ҳ�ǿ�����, UI�ⶫ���������µĻ��ͻ�����������ˡ����Ǹ���Ļ��⣬����̫���ˣ��ʹ˴�ס��

## ��Ҫ����
- ���ͨѶ,�¼�����
- �������,����
- ���߳�ͨѶ
- ����ͨѶ
- ��ʱ��

## CoreLooperԸ��

# CoreLooperΪʲôҪ��Դ

�����ܴ�������ļ�ֵ
���˱Ƚ�ϲ����ʫ�δʣ����ִ�������ѧ�Ϳ�Դ�����
��ʱϲ������ѧ����¼,����Щ��ѧ�һ���˺B,���ȿֺ�ķ����������ı���Լ���˼�룬Ψ������������һ��������ĳ���ش��֣����Ƿǳ�����˼���¡�

�������ÿ���˶����Լ����Ķ�����������ȱ�ٹ�ͨ�ͷ���,��������Ȥ�����ٺܶࡣ



�����ʹ������

* �����**һ���˿�**֧�ֶ�Э��ķ���, ����ʸ��ַ���
  * ���ڹ�ҵ����[RAFT�㷨](https://raft.github.io)ʵ�ִ[�߿���](https://en.wikipedia.org/wiki/High_availability)�ֲ�ʽϵͳ������[braft](https://github.com/brpc/braft)��Դ��
* Server��[ͬ��](docs/cn/server.md)��[�첽](docs/cn/server.md#�첽service)��������

## CoreLooper�������
- KISS ���ּ�����
ÿ���ӿڣ�����������������,����������ֵ������ȶ��������Ŀ���
- ����
���Ҫ������app���޺��÷�����������߷���,����ܱ����ܷ���
��������app��ε���ͬһHandler.Destroy()
- �޿ӻ��ٿ�
��ܾ����Ŭ���ṩ������񣬱������û��ȿ�
- ����򵥣�ʹ�÷���
���ǳ���Ҫ��ʹ�ÿ�ܵ��ż�Ҫ�ͣ���Ҫ��̫���������������ʸ���,����Ҫ����ʵʵ���ڵķ��㡣
- Ҫ��ƽ̨��֧��Ŀǰ�����Ĳ���ϵͳ
 ��ƽ̨��Ҫ�ṩͳһ�Ľӿ�,����ʹ��ĳƽ̨���еĹ���
- ����Ҫ���в��Է��㣬���ڿ����Դ�������� 
һ����Ʒ���������������Ӳ����������bug,��ȱ�ݲ������£��ⷴ���Ǻ����������顣ֻҪ�ܿ����Դ����������ܺܿ����ơ���������ԣ�����Ҫ�Ǿ��������Դ��ʱ��ɱ���һ������Ч�İ취���ǵ�Ԫ���ԡ�


### app����Ҫ�Լ�����
��ܲ�����Ϣ���У�sendMessage/postMessage�ܽ���������е�����,
app��ʹ��ʱһ�㲻��Ҫ����ͬ��
���app�õ��˼����������¿���һ��,ȷ����ȷ֪���Լ�����ʲô��


# ���״���

��ο�[����](CONTRIBUTING.md#chinese-version)��

# ��������

bug���޸Ľ��顢�ɻ󶼻�ӭ����issue�У������CoreLooper��������QQȺ484544131�������⡣



## Handler
Handler�ǿ�ܹ���Ļ�������������Android�е�Handler,MFC�е�CWnd��win32�е�HWND
Handler����ʹ��timer,��ͬһlooper�Ϳ�looper sendMessage����postMessage�충����Handler����Ϣ

### Handler��������

```mermaid
graph TD
A("Begin") -->|"����make_shared< Handler>()����Handler" |Start(Handler���캯��)
Start -->|Handler.Create����parent.AddChild,�󶨵�Looper| B(Handler::OnCreate)
B -->|Destroy| C(Handler::OnDestroy)
C -->|"���һ��ǿ������ʧʱ"| D(Handler �������� )
D --> End(End)

```
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

## Looper
Looper��Handler���࣬����ͨHandler��Looper��ͳһ���������ܴ�ı����������ڸ���Ӧ�ó����£��ǳ���Ȼ��������Ӧ���Ǳ�����״�����������Դ��Ŀ�ж�û�п��������Ƶ��÷���


## demo �÷�
### ��Android Message
```cpp
class MainLooper :public MainLooper_
{
	void OnCreate()
	{
		__super::OnCreate();

		class TestHandler :public Handler
		{
			void OnCreate()
			{
				__super::OnCreate();
				{
					auto msg = make_shared<Message>();
					msg->what = 2018;
					msg->arg1 = 9;
					msg->arg2 = 23;
					postMessage(msg);
				}
			}

			void HandleMessage(shared_ptr<Message> msg)
			{
				if (msg->what == 2018)
				{
					CurrentLooper()->PostQuitMessage();
				}
			}
		};

		AddChild(make_shared<TestHandler>());
	}
};

int main()
{
	return make_shared<MainLooper>()->StartRun();
	//�����Ҫlooperִ�еķ���ֵ,��ʹ��Looper.GetQuitCode()
}
```
### ��Android Activity���¼�
```cpp
class Activity :public Handler
{
public:
	const UINT mMessageStart = BindMessage(&Activity::OnStart);
	const UINT mMessageResume = BindMessage(&Activity::OnResume);
	const UINT mMessagePause = BindMessage(&Activity::OnPause);
	const UINT mMessageStop = BindMessage(&Activity::OnStop);
	const UINT mMessageRestart = BindMessage(&Activity::OnRestart);
	const UINT mMessageTest = BindMessage(&Activity::OnTest);
	//...
};

class MainLooper :public MainLooper_
{
	void OnCreate()
	{
		__super::OnCreate();

		auto obj = make_shared<Activity>();
		AddChild(obj);

		obj->sendMessage(obj->mMessageStart);
		obj->sendMessage(obj->mMessageResume);
		obj->sendMessage(obj->mMessagePause);
		obj->sendMessage(obj->mMessageStop);
		obj->sendMessage(obj->mMessageRestart);
		obj->sendMessage(obj->mMessageTest);

		PostQuitMessage();
	}
};


```
