ͼƬ���ɷ���:
https://mermaidjs.github.io/mermaid-live-editor
graph TD
A("Begin") -->|"����make_shared< Handler>()����Handler" |Start(Handler���캯��)
Start -->|Handler.Create����parent.AddChild,�󶨵�Looper| B(Handler::OnCreate)
B -->|Destroy| C(Handler::OnDestroy)
C -->|"���һ��ǿ������ʧʱ"| D(Handler �������� )
D --> End(End)

