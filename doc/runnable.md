# Runnable�ӿ�
����������CoreLooper.Runnable��Android.Runnable������ͬ(��ʵ��Java.Runnable)  
Java����Щ˼����ֵ��cpp����ġ�  
CoreLooper.Runnalbe�ӿ�����

```cpp
class Runnable :public std::enable_shared_from_this<Runnable>
{
public:
	virtual ~Runnable() {}

	virtual void Run() = 0;
};

```
Handler����Runnable��صĽӿ�
```cpp
	virtual LRESULT LOOPER_SAFE sendRunnable(shared_ptr<Runnable> obj);
	virtual LRESULT LOOPER_SAFE postRunnable(shared_ptr<Runnable> obj);
	virtual LRESULT LOOPER_SAFE postDelayedRunnable(shared_ptr<Runnable> obj, UINT ms);
	virtual void    LOOPER_SAFE cancelRunnable(shared_ptr<Runnable> obj);

```
����Handler����Looper����Runnable.Run()

sendRunnable��ִ��Runnable��ŷ���  
postRunnable��Ͷ�ݺ����Ϸ��أ�Looper���Ժ�ʱִ��  
postDelayedRunnable��Ͷ����ʱִ��,ms����ʱ������  
cancelRunnalbe��ȡ��postDelayedRunnableͶ��  

# �ڲ�ʵ��
CoreLooper�ڲ�������Ϣ+��ʱ��������Runnable
