# Looper
��CoreLooper�����,Looper��Handler���࣬����ͳһ������ͨHandler��Looper,�������ܴ�ı����������ڸ���Ӧ�ó����£��ǳ���Ȼ��������Ӧ���Ǳ�����״���Ŀǰ��������Դ��Ŀ�ж�û�п��������Ƶ�������

����Looper������Դ��Android.Looper,��Looper�������Ҫ���ܵ�Windows��������Windows api PostThreadMessage����threadҲ����Ӧ��Ϣ��CoreLooper������˼�뷢����Looper��ΪHandler������,֧��Handler�����нӿں����塣
## Looper��Ҫ�ӿ�
��Handler�Ļ�����,Looper��Ҫ���������½ӿ�
```cpp
	virtual int Start();//���µ��߳�������
	virtual int StartRun();//�ڵ�ǰOSԭ���߳���ֱ������,��Ҫ������main������
	virtual int  PostQuitMessage(int exitCode = 0);
	virtual int  GetQuitCode()const;

```
Looper�г�Աstring mThreadName,����ʱ������linux ps,windows vs�п����߳����ơ�
### ����Looper
```cpp
	auto looper = make_shared<WorkLooper>();
	AddChild(looper);
	looper->Start();
```
ע��Looper.Start()����һ���ᴴ���µ��̣߳������ܸ����̳߳��е��̡߳� 
ÿ���߳�ͬһʱ��ֻ��ֻ��һ��Looper,���󶨵�Looper����֮�󣬴��̲߳��ܰ󶨵��µ�Looper.

### �˳�Looper
```cpp
	looper->PostQuitMessage();
```
looper�յ�quit��Ϣʱ��ݹ�֪ͨ��������Handler���٣���������Handler����������˳�looper�̡߳�

