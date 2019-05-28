--[[
-- �����ĵ���Ҫ˵��
-- 
-- ����������
--		*update					USB������
--		*update_v1.0.7.lpk		����������
--		*update.txt				��������������: 
--			"hw_ver = h1.0.7"	�ļ�ϵͳ�汾
--			"sw_ver = v1.0.7"	����汾
--			"build_time = *"	����ʱ��, 
--			"*update (md5) = *"	USB�������ļ���md5ֵ
--			"*update_v1.0.7.lpk (md5) = *"	������������md5ֵ
--		�������.xlsx			��ǰ�汾��Ҫ����
-- ������Ƿ���ȷ�Ϸ�����Hash.exe����, �Ա��ļ�md5ֵ

һ. Ŀ¼�ṹ
	./
		Hash.exe		-- md5, sha1���ļ�У�鹤��
		md5sums.exe		-- winƽ̨������md5����
		llua.exe		-- ������ִ�г���
		curl.exe		-- ����������: http/https
		l_sdk.dll		-- sdk��
		*.dll			-- ����������̬��
	
	
	./demo				-- ���Խű�Ŀ¼
		readme.txt		-- ˵���ļ�
		target.lua		-- ����Ŀ���豸��Ϣ: IP��ַ,��¼��Ϣ,wifi��Ϣ
		t_nspp.lua		-- ����һ����nspp˽��Э�鼯��
		
		author.lua		-- lua�ű��淶
		curl.lua		-- ��װ����"curl.exe"ִ��http/https������
		login.lua		-- ��װͨ�õ�¼
		to_json.lua		-- ��װ��lua��tableת��Ϊjson�ı�
	
	
	./demo/nspp			-- ����˽��Э��ű�Ŀ¼
		t_base.lua		-- ���Ի�ȡ�豸������Ϣ: �����豸����
		t_discover.lua	-- ���Ծ��������鲥����
		t_login.lua		-- ���Ե�¼���豸
		
		t_m_stream_play.lua		-- ���Լ�����ȡ��·����, ����һ·����
		t_set_dhcp.lua			-- ����������������Ϊdhcp�Զ���ȡIP
		t_set_image.lua			-- ��������ͼ�����
		t_set_img_awb.lua		-- ��������ͼ���ƽ��
		t_set_img_flip.lua		-- ��������ͼ��ֱ��ת
		t_set_img_mirror.lua	-- ��������ͼ��ˮƽ����
		t_set_img_rotate.lua	-- ��������ͼ����ת
		t_set_ipv4.lua			-- ����������������Ϊ��̬IP��ַ
		t_set_stream.lua		-- ����������������
		t_set_stream_pic.lua	-- ��������ͼƬ������
		t_stream.lua			-- ������ȡһ·����,ֻ��ȡ��������
		t_stream_pic.lua		-- ������ȡͼƬ��, ��������ļ�
		t_stream_play.lua		-- ������ȡһ·����, ����һ·����
		t_upgrade.lua			-- ��������ָ�����豸,ָ���İ汾
		t_upgrade_auto.lua		-- ��������: �Ӿ������Զ������豸, �Զ�����ָ��Ŀ¼��������, �Զ�����
		t_wireless_set_ap.lua	-- ���������豸������Ϊ "AP"ģʽ(�����豸��Ϊ�ȵ�)
		t_wireless_set_dhcp.lua	-- �����豸��"STA"ģʽ��ʱ, �޸�����Ϊdhcp�Զ���ȡIP��ַ
		t_wireless_set_ipv4.lua	-- �����豸��"STA"ģʽ��ʱ, �޸�����Ϊ��̬IP��ַ
		t_wireless_set_sta.lua	-- ���������豸������Ϊ "STA"ģʽ(�����豸��Ϊ�ն����ӵ�wifi·����)
		

	./demo/http			-- ����httpЭ��ű�Ŀ¼
		-- �����


��. ȷ�ϲ���Ŀ����Ϣ, ���ļ� ./demo/target.lua
	1. Ŀ��IP��ַ: target.ip
	2. Ŀ��˿�: target.port
	3. ��Ҫ����WIFI��·��������: target.wifi_ssid
	4. ��Ҫ����WIFI��·��������: target.wifi_passwd


��. ���������л�����ǰĿ¼, ִ������: dir
	���ῴ�����´�ӡ:
	2018/12/24  09:34           830,536 curl.exe
	2019/03/18  17:02    <DIR>          demo
	2019/03/18  16:16           133,120 llua.exe
	2019/03/18  16:16           373,248 lua-5.3.5.dll
	2019/03/18  16:25            54,784 l_lua_res.dll
	2019/03/18  16:34         2,531,328 l_sdk.dll
	2019/03/12  13:50           144,896 l_tpool.dll
	

��. ���־��������豸, ִ������: llua.exe ./demo/nspp/t_discover.lua 
	���ῴ�����´�ӡ:
	multicast get devs:     {}
	multicast get devs:     [{"sn":"YDFE4EFDFESHEDFR","discover":{"mac":"00:13:09:FE:45:78","mac_wireless":"00:13:09:FE:45:79","name":"IPC","dev_type":"ipc","txt_enc":"","model":"wifi-ipc","port":80,"chnn_num":1,"sw_ver":"v1.0.7","hw_ver":"h1.0.7","md_enc":""},"ip":"192.168.1.247"}]
	

��. ���Ե�¼���豸, ִ������: llua.exe ./demo/nspp/t_login.lua
	���ῴ�����´�ӡ:
	login ok!id=1000        admin@192.168.3.218:80


��. ���Բ����豸����, ִ������: llua.exe ./demo/nspp/t_stream_play.lua
	���ῴ�����´�ӡ: ���һᵯ��һ��������ʾ�ֳ���Ƶ��
	login ok!id=1000        admin@192.168.3.218:80
	open stream ok!res={"cmd":"open_stream","open_stream":{"code":0}}


��. ������������
	1. �� ./demo/target.lua, ȷ��·����wifi���� �� ����
	
	2. �л���STAģʽ, ִ������: llua.exe ./demo/nspp/t_wireless_set_sta.lua
		login ok!id=1000        admin@192.168.3.218:80
		request set_wireless to sta, ret=0      res={"set_wireless":{"code":0},"cmd":"set_wireless"}
	
	3. �л���APģʽ, ִ������: llua.exe ./demo/nspp/t_wireless_set_ap.lua
		login ok!id=1000        admin@192.168.3.218:80
		request set_wireless to ap, ret=0       res={"set_wireless":{"code":0},"cmd":"set_wireless"}
		

��. ����ץȡͼƬ, ִ������: llua.exe ./demo/nspp/t_stream_pic.lua
	���ῴ�����´�ӡ: ����ɹ�, �ڵ�ǰĿ¼�ῴ��һϵ�е� *.jpg �ļ�
	login ok!id=1000        admin@192.168.3.218:80
	open stream ok!res={"open_stream":{"code":0},"cmd":"open_stream"}
		

��. ������������:
	llua.exe ./demo/nspp/t_base.lua
	llua.exe ./demo/nspp/t_stream.lua
	

ʮ. ������������: llua.exe ./demo/t_nspp.lua
	��ִ�и������Խű�		

ʮһ. ����:
	���޸�������ʵ�ʴ�ŵ�·��
	llua.exe ./demo/nspp/t_upgrade.lua
	
	���ῴ�����´�ӡ: 
	request upgrade:        0       {"cmd":"upgrade","upgrade":{"code":0}}
	status_upgrade: doing   1.0
	status_upgrade: doing   11.0
	status_upgrade: doing   21.0
	status_upgrade: doing   31.0
	status_upgrade: doing   41.0
	status_upgrade: doing   51.0
	status_upgrade: doing   61.0
	status_upgrade: doing   71.0
	status_upgrade: doing   81.0
	status_upgrade: doing   90.0
	status_upgrade: done    100.0	

--]]
