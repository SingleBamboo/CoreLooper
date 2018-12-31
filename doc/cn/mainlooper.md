# MainLooper
����ͷ���ߣ�����ͷ���ɡ�  
���¶������и�Դͷ
CoreLooper��������MainLooper�ĸ���
��������Android�е�Application�����MFC�е�CWinApp��
һ��app��Ӧ�����ҽ���һ��MainLooper

MainLooperֻ��һ��ռλ������ͨLooper����SetMainLooper(this)�����MainLooper��,�û���ʹ����������
MainLooper��ؽӿ�����
```cpp
	static Looper *GetMainLooper();
	static int SetMainLooper(Looper*);
	static bool IsMainLooper(LooperImpl *looper);
```

Ϊ����ʹ�ã�CoreLooper�����˰�����MainLooper_
```cpp
//main looper helper
class CORE_EXPORT MainLooper_ :public Looper
{
public:
	MainLooper_()
	{
		auto name = "MainLooper";
		SetObjectName(name);
		mThreadName = name;
		SetMainLooper(this);
	}
};
```
����һ�����ɼ�Ϊ
```cpp
	class MainLooper :public MainLooper_
	{
		//...
	};
```

MainLooper��Ҫ������main������,����

```cpp
int main()
{
	return make_shared<MainLooper>()->StartRun();
}
```
