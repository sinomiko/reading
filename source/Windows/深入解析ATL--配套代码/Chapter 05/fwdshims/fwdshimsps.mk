
fwdshimsps.dll: dlldata.obj fwdshims_p.obj fwdshims_i.obj
	link /dll /out:fwdshimsps.dll /def:fwdshimsps.def /entry:DllMain dlldata.obj fwdshims_p.obj fwdshims_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del fwdshimsps.dll
	@del fwdshimsps.lib
	@del fwdshimsps.exp
	@del dlldata.obj
	@del fwdshims_p.obj
	@del fwdshims_i.obj
