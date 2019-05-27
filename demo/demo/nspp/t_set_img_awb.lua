--[[
-- Copyright (c) 2019 �人˴�����, All Rights Reserved
-- Created: 2019/5/20
--
-- @brief	��������ͼ���ƽ��
-- @author	������
-- @see https://github.com/lishaoliang/l_sdk_doc/blob/master/protocol/image.md
--]]
local tostring = tostring
local string = require("string")
local l_sys = require("l_sys")
local l_sdk = require("l_sdk")
local cjson = require("cjson.safe")


local target = require("demo.target")
local to_json =  require("demo.to_json")
local login = require("demo.login")


-- sdk��ʼ��
l_sdk.init('')


-- ��¼���豸
local err, id = login(target.ip, target.port, target.username, target.passwd)


-- ��ӡ��¼���
if 0 ~= err then
	print('login error!'.. 'err=' .. err,  target.username .. '@' .. target.ip .. ':'..target.port .. ' -p ' .. target.passwd)
else	
	print('login ok!'.. 'id=' .. id, target.username .. '@' .. target.ip .. ':'..target.port)
end

-- ��ȡ��ƽ������
local t_get_img_awb = function (id, chnn)
		local req = {
		cmd = 'img_awb',
		--llssid = '123456',
		--llauth = '123456',
		img_awb = {
			chnn = chnn	-- 0
		}
	}
	
	local ret, res = l_sdk.request(id, to_json(req))
	print('request get img_awb,ret=' .. ret, 'res='..res)

	local dec = cjson.decode(res)
	
	local E = {}
	return ((dec or E).img_awb or E).awb
end

-- ���ð�ƽ������
local t_set_img_awb = function (id, chnn, awb, b, gb, gr, r)
	local req = {
		cmd = 'set_img_awb',
		--llssid = '123456',
		--llauth = '123456',
		set_img_awb = {
			chnn = chnn,		-- 0
			awb = awb,			-- 'auto', 'manual'
			b = b or 2047,		-- [0, 4095]
			gb = gb or 2047,	-- [0, 4095]
			gr = gr or 2047,	-- [0, 4095]
			r = r or 2047		-- [0, 4095]
		}
	}
	
	local ret, res = l_sdk.request(id, to_json(req))
	print('request set_img_awb, awb = ' .. tostring(awb) .. '. ' .. string.format('b/gb/gr/r=[%d,%d,%d,%d]', req.set_img_awb.b, req.set_img_awb.gb, req.set_img_awb.gr, req.set_img_awb.r))
	print('ret=' .. ret, 'res='..res)
end


local awb = t_get_img_awb(id, 0)
print('request,now img_awb = ' .. tostring(awb))


if 'auto' == awb then
	t_set_img_awb(id, 0, 'manual', l_sys.rand(4096) - 1, l_sys.rand(4096) - 1, l_sys.rand(4096) - 1, l_sys.rand(4096) - 1)
else
	t_set_img_awb(id, 0, 'auto')
end


-- ����3S
l_sys.sleep(3000)


-- �ǳ�
l_sdk.logout(id)


-- sdk�˳�
l_sdk.quit()
