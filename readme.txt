Ŀ¼˵��
demo		��ʾ����
depends		���������������
doc			�ĵ�
include		ͷ�ļ�
projects	vs,android stuido,xcode����
src			���Ĵ���

.��linux�±���
	����./c
	��./build.sh����
	����������demo,����:
	cd corelooper/build/release/bin
	./timer
	
	��ʾ��������
	./build.sh VERBOSE=1

.��windows�±���
	��vs2017��projects\libcorelooper\corelooper.sln
	��vs2017��demo\CoreLooperDemo.sln
	����demo��ͨ��unit test������
	ֱ�ӱ���,֧��x86��x64

.��android studio�±���
	��android studio��projects����.as��β���ļ���ֱ�ӱ���
	����
	projects/libcorelooper.as
