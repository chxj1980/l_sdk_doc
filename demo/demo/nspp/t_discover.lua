--[[
-- Copyright (c) 2019 �人˴�����, All Rights Reserved
-- Created: 2019/3/6
--
-- @brief	�����鲥�����豸
-- @author	������
-- @see https://github.com/lishaoliang/l_sdk_doc/blob/master/multicast/multicast.md
--]]
local l_sys = require("l_sys")
local l_sdk = require("l_sdk")


-- sdk��ʼ��
l_sdk.init('')


-- ���鲥�豸
l_sdk.multicast_open()


-- �����鲥����
l_sdk.multicast_discover(true)


local count = 11
while 0 < count do
	count = count - 1

	local devs = l_sdk.multicast_get_devs()
	print('multicast get devs:', devs)

	l_sys.sleep(1000)
end


-- �ر��鲥����
l_sdk.multicast_discover(false)


-- �ر��鲥�豸
l_sdk.multicast_close()

-- sdk�˳�
l_sdk.quit()
