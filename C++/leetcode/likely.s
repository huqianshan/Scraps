
.\a.exe:     file format pei-i386


Disassembly of section .text:

00401000 <.text>:
  401000:	83 ec 1c             	sub    $0x1c,%esp
  401003:	8b 44 24 20          	mov    0x20(%esp),%eax
  401007:	8b 00                	mov    (%eax),%eax
  401009:	8b 00                	mov    (%eax),%eax
  40100b:	3d 93 00 00 c0       	cmp    $0xc0000093,%eax
  401010:	74 1b                	je     40102d <.text+0x2d>
  401012:	77 4c                	ja     401060 <.text+0x60>
  401014:	3d 1d 00 00 c0       	cmp    $0xc000001d,%eax
  401019:	0f 84 cc 00 00 00    	je     4010eb <.text+0xeb>
  40101f:	76 7f                	jbe    4010a0 <.text+0xa0>
  401021:	05 73 ff ff 3f       	add    $0x3fffff73,%eax
  401026:	31 d2                	xor    %edx,%edx
  401028:	83 f8 04             	cmp    $0x4,%eax
  40102b:	77 27                	ja     401054 <.text+0x54>
  40102d:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
  401034:	00 
  401035:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
  40103c:	e8 63 2d 00 00       	call   403da4 <_signal>
  401041:	83 f8 01             	cmp    $0x1,%eax
  401044:	0f 84 d6 00 00 00    	je     401120 <.text+0x120>
  40104a:	85 c0                	test   %eax,%eax
  40104c:	0f 85 fe 00 00 00    	jne    401150 <.text+0x150>
  401052:	31 d2                	xor    %edx,%edx
  401054:	89 d0                	mov    %edx,%eax
  401056:	83 c4 1c             	add    $0x1c,%esp
  401059:	c2 04 00             	ret    $0x4
  40105c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  401060:	3d 94 00 00 c0       	cmp    $0xc0000094,%eax
  401065:	75 79                	jne    4010e0 <.text+0xe0>
  401067:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
  40106e:	00 
  40106f:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
  401076:	e8 29 2d 00 00       	call   403da4 <_signal>
  40107b:	83 f8 01             	cmp    $0x1,%eax
  40107e:	75 ca                	jne    40104a <.text+0x4a>
  401080:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
  401087:	00 
  401088:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
  40108f:	e8 10 2d 00 00       	call   403da4 <_signal>
  401094:	ba ff ff ff ff       	mov    $0xffffffff,%edx
  401099:	eb b9                	jmp    401054 <.text+0x54>
  40109b:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  40109f:	90                   	nop
  4010a0:	3d 05 00 00 c0       	cmp    $0xc0000005,%eax
  4010a5:	75 ab                	jne    401052 <.text+0x52>
  4010a7:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
  4010ae:	00 
  4010af:	c7 04 24 0b 00 00 00 	movl   $0xb,(%esp)
  4010b6:	e8 e9 2c 00 00       	call   403da4 <_signal>
  4010bb:	83 f8 01             	cmp    $0x1,%eax
  4010be:	0f 84 9f 00 00 00    	je     401163 <.text+0x163>
  4010c4:	85 c0                	test   %eax,%eax
  4010c6:	74 8a                	je     401052 <.text+0x52>
  4010c8:	c7 04 24 0b 00 00 00 	movl   $0xb,(%esp)
  4010cf:	ff d0                	call   *%eax
  4010d1:	ba ff ff ff ff       	mov    $0xffffffff,%edx
  4010d6:	e9 79 ff ff ff       	jmp    401054 <.text+0x54>
  4010db:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  4010df:	90                   	nop
  4010e0:	3d 96 00 00 c0       	cmp    $0xc0000096,%eax
  4010e5:	0f 85 67 ff ff ff    	jne    401052 <.text+0x52>
  4010eb:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
  4010f2:	00 
  4010f3:	c7 04 24 04 00 00 00 	movl   $0x4,(%esp)
  4010fa:	e8 a5 2c 00 00       	call   403da4 <_signal>
  4010ff:	83 f8 01             	cmp    $0x1,%eax
  401102:	74 7b                	je     40117f <.text+0x17f>
  401104:	85 c0                	test   %eax,%eax
  401106:	0f 84 46 ff ff ff    	je     401052 <.text+0x52>
  40110c:	c7 04 24 04 00 00 00 	movl   $0x4,(%esp)
  401113:	ff d0                	call   *%eax
  401115:	ba ff ff ff ff       	mov    $0xffffffff,%edx
  40111a:	e9 35 ff ff ff       	jmp    401054 <.text+0x54>
  40111f:	90                   	nop
  401120:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
  401127:	00 
  401128:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
  40112f:	e8 70 2c 00 00       	call   403da4 <_signal>
  401134:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
  40113b:	e8 b0 0e 00 00       	call   401ff0 <_fesetenv>
  401140:	ba ff ff ff ff       	mov    $0xffffffff,%edx
  401145:	e9 0a ff ff ff       	jmp    401054 <.text+0x54>
  40114a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  401150:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
  401157:	ff d0                	call   *%eax
  401159:	ba ff ff ff ff       	mov    $0xffffffff,%edx
  40115e:	e9 f1 fe ff ff       	jmp    401054 <.text+0x54>
  401163:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
  40116a:	00 
  40116b:	c7 04 24 0b 00 00 00 	movl   $0xb,(%esp)
  401172:	e8 2d 2c 00 00       	call   403da4 <_signal>
  401177:	83 ca ff             	or     $0xffffffff,%edx
  40117a:	e9 d5 fe ff ff       	jmp    401054 <.text+0x54>
  40117f:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
  401186:	00 
  401187:	c7 04 24 04 00 00 00 	movl   $0x4,(%esp)
  40118e:	e8 11 2c 00 00       	call   403da4 <_signal>
  401193:	83 ca ff             	or     $0xffffffff,%edx
  401196:	e9 b9 fe ff ff       	jmp    401054 <.text+0x54>
  40119b:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  40119f:	90                   	nop
  4011a0:	53                   	push   %ebx
  4011a1:	83 ec 18             	sub    $0x18,%esp
  4011a4:	a1 54 51 40 00       	mov    0x405154,%eax
  4011a9:	85 c0                	test   %eax,%eax
  4011ab:	74 1c                	je     4011c9 <.text+0x1c9>
  4011ad:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
  4011b4:	00 
  4011b5:	c7 44 24 04 02 00 00 	movl   $0x2,0x4(%esp)
  4011bc:	00 
  4011bd:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
  4011c4:	ff d0                	call   *%eax
  4011c6:	83 ec 0c             	sub    $0xc,%esp
  4011c9:	c7 04 24 00 10 40 00 	movl   $0x401000,(%esp)
  4011d0:	e8 87 2c 00 00       	call   403e5c <_SetUnhandledExceptionFilter@4>
  4011d5:	83 ec 04             	sub    $0x4,%esp
  4011d8:	e8 d3 05 00 00       	call   4017b0 <___cpu_features_init>
  4011dd:	a1 08 40 40 00       	mov    0x404008,%eax
  4011e2:	89 04 24             	mov    %eax,(%esp)
  4011e5:	e8 06 0e 00 00       	call   401ff0 <_fesetenv>
  4011ea:	e8 21 02 00 00       	call   401410 <__setargv>
  4011ef:	a1 20 70 40 00       	mov    0x407020,%eax
  4011f4:	85 c0                	test   %eax,%eax
  4011f6:	75 4a                	jne    401242 <.text+0x242>
  4011f8:	e8 2f 2c 00 00       	call   403e2c <___p__fmode>
  4011fd:	8b 15 0c 40 40 00    	mov    0x40400c,%edx
  401203:	89 10                	mov    %edx,(%eax)
  401205:	e8 f6 0b 00 00       	call   401e00 <__pei386_runtime_relocator>
  40120a:	83 e4 f0             	and    $0xfffffff0,%esp
  40120d:	e8 4e 07 00 00       	call   401960 <___main>
  401212:	e8 1d 2c 00 00       	call   403e34 <___p__environ>
  401217:	8b 00                	mov    (%eax),%eax
  401219:	89 44 24 08          	mov    %eax,0x8(%esp)
  40121d:	a1 00 70 40 00       	mov    0x407000,%eax
  401222:	89 44 24 04          	mov    %eax,0x4(%esp)
  401226:	a1 04 70 40 00       	mov    0x407004,%eax
  40122b:	89 04 24             	mov    %eax,(%esp)
  40122e:	e8 ad 2c 00 00       	call   403ee0 <_main>
  401233:	89 c3                	mov    %eax,%ebx
  401235:	e8 ea 2b 00 00       	call   403e24 <__cexit>
  40123a:	89 1c 24             	mov    %ebx,(%esp)
  40123d:	e8 7a 2c 00 00       	call   403ebc <_ExitProcess@4>
  401242:	8b 1d b0 81 40 00    	mov    0x4081b0,%ebx
  401248:	89 44 24 04          	mov    %eax,0x4(%esp)
  40124c:	a3 0c 40 40 00       	mov    %eax,0x40400c
  401251:	8b 43 10             	mov    0x10(%ebx),%eax
  401254:	89 04 24             	mov    %eax,(%esp)
  401257:	e8 a0 2b 00 00       	call   403dfc <__setmode>
  40125c:	a1 20 70 40 00       	mov    0x407020,%eax
  401261:	89 44 24 04          	mov    %eax,0x4(%esp)
  401265:	8b 43 30             	mov    0x30(%ebx),%eax
  401268:	89 04 24             	mov    %eax,(%esp)
  40126b:	e8 8c 2b 00 00       	call   403dfc <__setmode>
  401270:	a1 20 70 40 00       	mov    0x407020,%eax
  401275:	89 44 24 04          	mov    %eax,0x4(%esp)
  401279:	8b 43 50             	mov    0x50(%ebx),%eax
  40127c:	89 04 24             	mov    %eax,(%esp)
  40127f:	e8 78 2b 00 00       	call   403dfc <__setmode>
  401284:	e9 6f ff ff ff       	jmp    4011f8 <.text+0x1f8>
  401289:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi

00401290 <__mingw32_init_mainargs>:
  401290:	83 ec 3c             	sub    $0x3c,%esp
  401293:	8d 44 24 2c          	lea    0x2c(%esp),%eax
  401297:	c7 44 24 04 00 70 40 	movl   $0x407000,0x4(%esp)
  40129e:	00 
  40129f:	89 44 24 10          	mov    %eax,0x10(%esp)
  4012a3:	a1 04 40 40 00       	mov    0x404004,%eax
  4012a8:	c7 04 24 04 70 40 00 	movl   $0x407004,(%esp)
  4012af:	83 e0 01             	and    $0x1,%eax
  4012b2:	c7 44 24 2c 00 00 00 	movl   $0x0,0x2c(%esp)
  4012b9:	00 
  4012ba:	89 44 24 0c          	mov    %eax,0xc(%esp)
  4012be:	8d 44 24 28          	lea    0x28(%esp),%eax
  4012c2:	89 44 24 08          	mov    %eax,0x8(%esp)
  4012c6:	e8 71 2b 00 00       	call   403e3c <___getmainargs>
  4012cb:	83 c4 3c             	add    $0x3c,%esp
  4012ce:	c3                   	ret    
  4012cf:	90                   	nop

004012d0 <_mainCRTStartup>:
  4012d0:	83 ec 1c             	sub    $0x1c,%esp
  4012d3:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
  4012da:	ff 15 9c 81 40 00    	call   *0x40819c
  4012e0:	e8 bb fe ff ff       	call   4011a0 <.text+0x1a0>
  4012e5:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  4012ec:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi

004012f0 <_WinMainCRTStartup>:
  4012f0:	83 ec 1c             	sub    $0x1c,%esp
  4012f3:	c7 04 24 02 00 00 00 	movl   $0x2,(%esp)
  4012fa:	ff 15 9c 81 40 00    	call   *0x40819c
  401300:	e8 9b fe ff ff       	call   4011a0 <.text+0x1a0>
  401305:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  40130c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi

00401310 <_atexit>:
  401310:	ff 25 cc 81 40 00    	jmp    *0x4081cc
  401316:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  40131d:	8d 76 00             	lea    0x0(%esi),%esi

00401320 <__onexit>:
  401320:	ff 25 bc 81 40 00    	jmp    *0x4081bc
  401326:	90                   	nop
  401327:	90                   	nop
  401328:	90                   	nop
  401329:	90                   	nop
  40132a:	90                   	nop
  40132b:	90                   	nop
  40132c:	90                   	nop
  40132d:	90                   	nop
  40132e:	90                   	nop
  40132f:	90                   	nop

00401330 <___gcc_register_frame>:
  401330:	55                   	push   %ebp
  401331:	89 e5                	mov    %esp,%ebp
  401333:	56                   	push   %esi
  401334:	53                   	push   %ebx
  401335:	83 ec 10             	sub    $0x10,%esp
  401338:	c7 04 24 00 50 40 00 	movl   $0x405000,(%esp)
  40133f:	e8 40 2b 00 00       	call   403e84 <_GetModuleHandleA@4>
  401344:	83 ec 04             	sub    $0x4,%esp
  401347:	85 c0                	test   %eax,%eax
  401349:	74 75                	je     4013c0 <___gcc_register_frame+0x90>
  40134b:	c7 04 24 00 50 40 00 	movl   $0x405000,(%esp)
  401352:	89 c3                	mov    %eax,%ebx
  401354:	e8 0b 2b 00 00       	call   403e64 <_LoadLibraryA@4>
  401359:	83 ec 04             	sub    $0x4,%esp
  40135c:	a3 70 70 40 00       	mov    %eax,0x407070
  401361:	c7 44 24 04 13 50 40 	movl   $0x405013,0x4(%esp)
  401368:	00 
  401369:	89 1c 24             	mov    %ebx,(%esp)
  40136c:	e8 0b 2b 00 00       	call   403e7c <_GetProcAddress@8>
  401371:	83 ec 08             	sub    $0x8,%esp
  401374:	89 c6                	mov    %eax,%esi
  401376:	c7 44 24 04 29 50 40 	movl   $0x405029,0x4(%esp)
  40137d:	00 
  40137e:	89 1c 24             	mov    %ebx,(%esp)
  401381:	e8 f6 2a 00 00       	call   403e7c <_GetProcAddress@8>
  401386:	a3 00 40 40 00       	mov    %eax,0x404000
  40138b:	83 ec 08             	sub    $0x8,%esp
  40138e:	85 f6                	test   %esi,%esi
  401390:	74 11                	je     4013a3 <___gcc_register_frame+0x73>
  401392:	c7 44 24 04 08 70 40 	movl   $0x407008,0x4(%esp)
  401399:	00 
  40139a:	c7 04 24 c8 60 40 00 	movl   $0x4060c8,(%esp)
  4013a1:	ff d6                	call   *%esi
  4013a3:	c7 04 24 e0 13 40 00 	movl   $0x4013e0,(%esp)
  4013aa:	e8 61 ff ff ff       	call   401310 <_atexit>
  4013af:	8d 65 f8             	lea    -0x8(%ebp),%esp
  4013b2:	5b                   	pop    %ebx
  4013b3:	5e                   	pop    %esi
  4013b4:	5d                   	pop    %ebp
  4013b5:	c3                   	ret    
  4013b6:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  4013bd:	8d 76 00             	lea    0x0(%esi),%esi
  4013c0:	c7 05 00 40 40 00 00 	movl   $0x0,0x404000
  4013c7:	00 00 00 
  4013ca:	be 00 00 00 00       	mov    $0x0,%esi
  4013cf:	eb bd                	jmp    40138e <___gcc_register_frame+0x5e>
  4013d1:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  4013d8:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  4013df:	90                   	nop

004013e0 <___gcc_deregister_frame>:
  4013e0:	55                   	push   %ebp
  4013e1:	89 e5                	mov    %esp,%ebp
  4013e3:	83 ec 18             	sub    $0x18,%esp
  4013e6:	a1 00 40 40 00       	mov    0x404000,%eax
  4013eb:	85 c0                	test   %eax,%eax
  4013ed:	74 09                	je     4013f8 <___gcc_deregister_frame+0x18>
  4013ef:	c7 04 24 c8 60 40 00 	movl   $0x4060c8,(%esp)
  4013f6:	ff d0                	call   *%eax
  4013f8:	a1 70 70 40 00       	mov    0x407070,%eax
  4013fd:	85 c0                	test   %eax,%eax
  4013ff:	74 0b                	je     40140c <___gcc_deregister_frame+0x2c>
  401401:	89 04 24             	mov    %eax,(%esp)
  401404:	e8 93 2a 00 00       	call   403e9c <_FreeLibrary@4>
  401409:	83 ec 04             	sub    $0x4,%esp
  40140c:	c9                   	leave  
  40140d:	c3                   	ret    
  40140e:	90                   	nop
  40140f:	90                   	nop

00401410 <__setargv>:
  401410:	55                   	push   %ebp
  401411:	89 e5                	mov    %esp,%ebp
  401413:	57                   	push   %edi
  401414:	56                   	push   %esi
  401415:	53                   	push   %ebx
  401416:	83 ec 4c             	sub    $0x4c,%esp
  401419:	f6 05 04 40 40 00 02 	testb  $0x2,0x404004
  401420:	75 0e                	jne    401430 <__setargv+0x20>
  401422:	e8 69 fe ff ff       	call   401290 <__mingw32_init_mainargs>
  401427:	8d 65 f4             	lea    -0xc(%ebp),%esp
  40142a:	5b                   	pop    %ebx
  40142b:	5e                   	pop    %esi
  40142c:	5f                   	pop    %edi
  40142d:	5d                   	pop    %ebp
  40142e:	c3                   	ret    
  40142f:	90                   	nop
  401430:	e8 5f 2a 00 00       	call   403e94 <_GetCommandLineA@0>
  401435:	89 65 c0             	mov    %esp,-0x40(%ebp)
  401438:	89 04 24             	mov    %eax,(%esp)
  40143b:	89 c3                	mov    %eax,%ebx
  40143d:	e8 52 29 00 00       	call   403d94 <_strlen>
  401442:	8d 44 00 11          	lea    0x11(%eax,%eax,1),%eax
  401446:	c1 e8 04             	shr    $0x4,%eax
  401449:	c1 e0 04             	shl    $0x4,%eax
  40144c:	e8 ef 28 00 00       	call   403d40 <___chkstk_ms>
  401451:	29 c4                	sub    %eax,%esp
  401453:	a1 04 40 40 00       	mov    0x404004,%eax
  401458:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%ebp)
  40145f:	0f be 3b             	movsbl (%ebx),%edi
  401462:	8d 74 24 10          	lea    0x10(%esp),%esi
  401466:	25 00 44 00 00       	and    $0x4400,%eax
  40146b:	89 75 c8             	mov    %esi,-0x38(%ebp)
  40146e:	83 c8 10             	or     $0x10,%eax
  401471:	89 45 c4             	mov    %eax,-0x3c(%ebp)
  401474:	8d 43 01             	lea    0x1(%ebx),%eax
  401477:	89 fb                	mov    %edi,%ebx
  401479:	89 45 d4             	mov    %eax,-0x2c(%ebp)
  40147c:	85 ff                	test   %edi,%edi
  40147e:	0f 84 cc 00 00 00    	je     401550 <__setargv+0x140>
  401484:	c7 45 cc 00 00 00 00 	movl   $0x0,-0x34(%ebp)
  40148b:	89 f0                	mov    %esi,%eax
  40148d:	31 d2                	xor    %edx,%edx
  40148f:	c7 45 d0 00 00 00 00 	movl   $0x0,-0x30(%ebp)
  401496:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  40149d:	8d 76 00             	lea    0x0(%esi),%esi
  4014a0:	80 fb 3f             	cmp    $0x3f,%bl
  4014a3:	0f 8f 57 02 00 00    	jg     401700 <__setargv+0x2f0>
  4014a9:	80 fb 21             	cmp    $0x21,%bl
  4014ac:	0f 8f 5e 01 00 00    	jg     401610 <__setargv+0x200>
  4014b2:	8d 34 10             	lea    (%eax,%edx,1),%esi
  4014b5:	85 d2                	test   %edx,%edx
  4014b7:	0f 84 d2 02 00 00    	je     40178f <__setargv+0x37f>
  4014bd:	8d 76 00             	lea    0x0(%esi),%esi
  4014c0:	83 c0 01             	add    $0x1,%eax
  4014c3:	c6 40 ff 5c          	movb   $0x5c,-0x1(%eax)
  4014c7:	39 f0                	cmp    %esi,%eax
  4014c9:	75 f5                	jne    4014c0 <__setargv+0xb0>
  4014cb:	8b 4d d0             	mov    -0x30(%ebp),%ecx
  4014ce:	85 c9                	test   %ecx,%ecx
  4014d0:	0f 85 c2 00 00 00    	jne    401598 <__setargv+0x188>
  4014d6:	a1 90 81 40 00       	mov    0x408190,%eax
  4014db:	83 38 01             	cmpl   $0x1,(%eax)
  4014de:	0f 85 8c 00 00 00    	jne    401570 <__setargv+0x160>
  4014e4:	a1 c0 81 40 00       	mov    0x4081c0,%eax
  4014e9:	8b 00                	mov    (%eax),%eax
  4014eb:	f6 04 78 40          	testb  $0x40,(%eax,%edi,2)
  4014ef:	0f 84 93 00 00 00    	je     401588 <__setargv+0x178>
  4014f5:	39 75 c8             	cmp    %esi,-0x38(%ebp)
  4014f8:	0f 82 d2 00 00 00    	jb     4015d0 <__setargv+0x1c0>
  4014fe:	8b 55 cc             	mov    -0x34(%ebp),%edx
  401501:	85 d2                	test   %edx,%edx
  401503:	0f 85 c7 00 00 00    	jne    4015d0 <__setargv+0x1c0>
  401509:	c7 45 cc 00 00 00 00 	movl   $0x0,-0x34(%ebp)
  401510:	89 f0                	mov    %esi,%eax
  401512:	31 d2                	xor    %edx,%edx
  401514:	e9 86 00 00 00       	jmp    40159f <__setargv+0x18f>
  401519:	89 c2                	mov    %eax,%edx
  40151b:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  40151f:	90                   	nop
  401520:	39 55 c8             	cmp    %edx,-0x38(%ebp)
  401523:	72 07                	jb     40152c <__setargv+0x11c>
  401525:	8b 45 cc             	mov    -0x34(%ebp),%eax
  401528:	85 c0                	test   %eax,%eax
  40152a:	74 24                	je     401550 <__setargv+0x140>
  40152c:	8d 45 d8             	lea    -0x28(%ebp),%eax
  40152f:	c6 02 00             	movb   $0x0,(%edx)
  401532:	89 44 24 0c          	mov    %eax,0xc(%esp)
  401536:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
  40153d:	00 
  40153e:	8b 45 c4             	mov    -0x3c(%ebp),%eax
  401541:	89 44 24 04          	mov    %eax,0x4(%esp)
  401545:	8b 45 c8             	mov    -0x38(%ebp),%eax
  401548:	89 04 24             	mov    %eax,(%esp)
  40154b:	e8 f0 1a 00 00       	call   403040 <___mingw_glob>
  401550:	8b 45 dc             	mov    -0x24(%ebp),%eax
  401553:	a3 04 70 40 00       	mov    %eax,0x407004
  401558:	8b 45 e0             	mov    -0x20(%ebp),%eax
  40155b:	a3 00 70 40 00       	mov    %eax,0x407000
  401560:	8b 65 c0             	mov    -0x40(%ebp),%esp
  401563:	8d 65 f4             	lea    -0xc(%ebp),%esp
  401566:	5b                   	pop    %ebx
  401567:	5e                   	pop    %esi
  401568:	5f                   	pop    %edi
  401569:	5d                   	pop    %ebp
  40156a:	c3                   	ret    
  40156b:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  40156f:	90                   	nop
  401570:	c7 44 24 04 40 00 00 	movl   $0x40,0x4(%esp)
  401577:	00 
  401578:	89 3c 24             	mov    %edi,(%esp)
  40157b:	e8 8c 28 00 00       	call   403e0c <__isctype>
  401580:	85 c0                	test   %eax,%eax
  401582:	0f 85 6d ff ff ff    	jne    4014f5 <__setargv+0xe5>
  401588:	83 ff 09             	cmp    $0x9,%edi
  40158b:	0f 84 64 ff ff ff    	je     4014f5 <__setargv+0xe5>
  401591:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  401598:	88 1e                	mov    %bl,(%esi)
  40159a:	8d 46 01             	lea    0x1(%esi),%eax
  40159d:	31 d2                	xor    %edx,%edx
  40159f:	83 45 d4 01          	addl   $0x1,-0x2c(%ebp)
  4015a3:	8b 7d d4             	mov    -0x2c(%ebp),%edi
  4015a6:	0f be 7f ff          	movsbl -0x1(%edi),%edi
  4015aa:	89 fb                	mov    %edi,%ebx
  4015ac:	85 ff                	test   %edi,%edi
  4015ae:	0f 85 ec fe ff ff    	jne    4014a0 <__setargv+0x90>
  4015b4:	85 d2                	test   %edx,%edx
  4015b6:	0f 84 5d ff ff ff    	je     401519 <__setargv+0x109>
  4015bc:	01 c2                	add    %eax,%edx
  4015be:	66 90                	xchg   %ax,%ax
  4015c0:	83 c0 01             	add    $0x1,%eax
  4015c3:	c6 40 ff 5c          	movb   $0x5c,-0x1(%eax)
  4015c7:	39 d0                	cmp    %edx,%eax
  4015c9:	75 f5                	jne    4015c0 <__setargv+0x1b0>
  4015cb:	e9 50 ff ff ff       	jmp    401520 <__setargv+0x110>
  4015d0:	8d 45 d8             	lea    -0x28(%ebp),%eax
  4015d3:	c6 06 00             	movb   $0x0,(%esi)
  4015d6:	89 44 24 0c          	mov    %eax,0xc(%esp)
  4015da:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
  4015e1:	00 
  4015e2:	8b 75 c4             	mov    -0x3c(%ebp),%esi
  4015e5:	89 74 24 04          	mov    %esi,0x4(%esp)
  4015e9:	8b 7d c8             	mov    -0x38(%ebp),%edi
  4015ec:	83 ce 01             	or     $0x1,%esi
  4015ef:	89 3c 24             	mov    %edi,(%esp)
  4015f2:	e8 49 1a 00 00       	call   403040 <___mingw_glob>
  4015f7:	89 75 c4             	mov    %esi,-0x3c(%ebp)
  4015fa:	89 f8                	mov    %edi,%eax
  4015fc:	31 d2                	xor    %edx,%edx
  4015fe:	c7 45 cc 00 00 00 00 	movl   $0x0,-0x34(%ebp)
  401605:	eb 98                	jmp    40159f <__setargv+0x18f>
  401607:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  40160e:	66 90                	xchg   %ax,%ax
  401610:	8d 4b de             	lea    -0x22(%ebx),%ecx
  401613:	80 f9 1d             	cmp    $0x1d,%cl
  401616:	0f 87 96 fe ff ff    	ja     4014b2 <__setargv+0xa2>
  40161c:	0f b6 c9             	movzbl %cl,%ecx
  40161f:	ff 24 8d 48 50 40 00 	jmp    *0x405048(,%ecx,4)
  401626:	8d 72 ff             	lea    -0x1(%edx),%esi
  401629:	83 ff 7f             	cmp    $0x7f,%edi
  40162c:	0f 94 c1             	sete   %cl
  40162f:	89 cf                	mov    %ecx,%edi
  401631:	8b 4d d0             	mov    -0x30(%ebp),%ecx
  401634:	85 c9                	test   %ecx,%ecx
  401636:	0f 95 c1             	setne  %cl
  401639:	09 f9                	or     %edi,%ecx
  40163b:	85 d2                	test   %edx,%edx
  40163d:	0f 84 53 01 00 00    	je     401796 <__setargv+0x386>
  401643:	8d 54 30 01          	lea    0x1(%eax,%esi,1),%edx
  401647:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  40164e:	66 90                	xchg   %ax,%ax
  401650:	83 c0 01             	add    $0x1,%eax
  401653:	c6 40 ff 5c          	movb   $0x5c,-0x1(%eax)
  401657:	39 d0                	cmp    %edx,%eax
  401659:	75 f5                	jne    401650 <__setargv+0x240>
  40165b:	89 d6                	mov    %edx,%esi
  40165d:	84 c9                	test   %cl,%cl
  40165f:	0f 84 33 ff ff ff    	je     401598 <__setargv+0x188>
  401665:	c6 02 7f             	movb   $0x7f,(%edx)
  401668:	8d 72 01             	lea    0x1(%edx),%esi
  40166b:	e9 28 ff ff ff       	jmp    401598 <__setargv+0x188>
  401670:	f6 05 04 40 40 00 10 	testb  $0x10,0x404004
  401677:	0f 84 35 fe ff ff    	je     4014b2 <__setargv+0xa2>
  40167d:	89 d1                	mov    %edx,%ecx
  40167f:	d1 f9                	sar    %ecx
  401681:	0f 84 1d 01 00 00    	je     4017a4 <__setargv+0x394>
  401687:	01 c1                	add    %eax,%ecx
  401689:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  401690:	83 c0 01             	add    $0x1,%eax
  401693:	c6 40 ff 5c          	movb   $0x5c,-0x1(%eax)
  401697:	39 c8                	cmp    %ecx,%eax
  401699:	75 f5                	jne    401690 <__setargv+0x280>
  40169b:	83 7d d0 22          	cmpl   $0x22,-0x30(%ebp)
  40169f:	74 09                	je     4016aa <__setargv+0x29a>
  4016a1:	83 e2 01             	and    $0x1,%edx
  4016a4:	0f 84 d1 00 00 00    	je     40177b <__setargv+0x36b>
  4016aa:	c6 01 27             	movb   $0x27,(%ecx)
  4016ad:	8d 41 01             	lea    0x1(%ecx),%eax
  4016b0:	31 d2                	xor    %edx,%edx
  4016b2:	c7 45 cc 01 00 00 00 	movl   $0x1,-0x34(%ebp)
  4016b9:	e9 e1 fe ff ff       	jmp    40159f <__setargv+0x18f>
  4016be:	89 d1                	mov    %edx,%ecx
  4016c0:	d1 f9                	sar    %ecx
  4016c2:	0f 84 d5 00 00 00    	je     40179d <__setargv+0x38d>
  4016c8:	01 c1                	add    %eax,%ecx
  4016ca:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  4016d0:	83 c0 01             	add    $0x1,%eax
  4016d3:	c6 40 ff 5c          	movb   $0x5c,-0x1(%eax)
  4016d7:	39 c8                	cmp    %ecx,%eax
  4016d9:	75 f5                	jne    4016d0 <__setargv+0x2c0>
  4016db:	83 7d d0 27          	cmpl   $0x27,-0x30(%ebp)
  4016df:	74 77                	je     401758 <__setargv+0x348>
  4016e1:	83 e2 01             	and    $0x1,%edx
  4016e4:	75 72                	jne    401758 <__setargv+0x348>
  4016e6:	83 75 d0 22          	xorl   $0x22,-0x30(%ebp)
  4016ea:	89 c8                	mov    %ecx,%eax
  4016ec:	31 d2                	xor    %edx,%edx
  4016ee:	c7 45 cc 01 00 00 00 	movl   $0x1,-0x34(%ebp)
  4016f5:	e9 a5 fe ff ff       	jmp    40159f <__setargv+0x18f>
  4016fa:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  401700:	80 fb 5a             	cmp    $0x5a,%bl
  401703:	0f 8e a9 fd ff ff    	jle    4014b2 <__setargv+0xa2>
  401709:	8d 4b a5             	lea    -0x5b(%ebx),%ecx
  40170c:	80 f9 24             	cmp    $0x24,%cl
  40170f:	0f 87 9d fd ff ff    	ja     4014b2 <__setargv+0xa2>
  401715:	0f b6 c9             	movzbl %cl,%ecx
  401718:	ff 24 8d c0 50 40 00 	jmp    *0x4050c0(,%ecx,4)
  40171f:	83 7d d0 27          	cmpl   $0x27,-0x30(%ebp)
  401723:	74 4b                	je     401770 <__setargv+0x360>
  401725:	83 c2 01             	add    $0x1,%edx
  401728:	e9 72 fe ff ff       	jmp    40159f <__setargv+0x18f>
  40172d:	8d 72 ff             	lea    -0x1(%edx),%esi
  401730:	f6 05 04 40 40 00 20 	testb  $0x20,0x404004
  401737:	0f 85 ec fe ff ff    	jne    401629 <__setargv+0x219>
  40173d:	b9 01 00 00 00       	mov    $0x1,%ecx
  401742:	85 d2                	test   %edx,%edx
  401744:	0f 85 f9 fe ff ff    	jne    401643 <__setargv+0x233>
  40174a:	89 c2                	mov    %eax,%edx
  40174c:	e9 14 ff ff ff       	jmp    401665 <__setargv+0x255>
  401751:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  401758:	c6 01 22             	movb   $0x22,(%ecx)
  40175b:	8d 41 01             	lea    0x1(%ecx),%eax
  40175e:	31 d2                	xor    %edx,%edx
  401760:	c7 45 cc 01 00 00 00 	movl   $0x1,-0x34(%ebp)
  401767:	e9 33 fe ff ff       	jmp    40159f <__setargv+0x18f>
  40176c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  401770:	c6 00 5c             	movb   $0x5c,(%eax)
  401773:	83 c0 01             	add    $0x1,%eax
  401776:	e9 24 fe ff ff       	jmp    40159f <__setargv+0x18f>
  40177b:	83 75 d0 27          	xorl   $0x27,-0x30(%ebp)
  40177f:	89 c8                	mov    %ecx,%eax
  401781:	31 d2                	xor    %edx,%edx
  401783:	c7 45 cc 01 00 00 00 	movl   $0x1,-0x34(%ebp)
  40178a:	e9 10 fe ff ff       	jmp    40159f <__setargv+0x18f>
  40178f:	89 c6                	mov    %eax,%esi
  401791:	e9 35 fd ff ff       	jmp    4014cb <__setargv+0xbb>
  401796:	89 c2                	mov    %eax,%edx
  401798:	e9 be fe ff ff       	jmp    40165b <__setargv+0x24b>
  40179d:	89 c1                	mov    %eax,%ecx
  40179f:	e9 37 ff ff ff       	jmp    4016db <__setargv+0x2cb>
  4017a4:	89 c1                	mov    %eax,%ecx
  4017a6:	e9 f0 fe ff ff       	jmp    40169b <__setargv+0x28b>
  4017ab:	90                   	nop
  4017ac:	90                   	nop
  4017ad:	90                   	nop
  4017ae:	90                   	nop
  4017af:	90                   	nop

004017b0 <___cpu_features_init>:
  4017b0:	9c                   	pushf  
  4017b1:	9c                   	pushf  
  4017b2:	58                   	pop    %eax
  4017b3:	89 c2                	mov    %eax,%edx
  4017b5:	35 00 00 20 00       	xor    $0x200000,%eax
  4017ba:	50                   	push   %eax
  4017bb:	9d                   	popf   
  4017bc:	9c                   	pushf  
  4017bd:	58                   	pop    %eax
  4017be:	9d                   	popf   
  4017bf:	31 d0                	xor    %edx,%eax
  4017c1:	a9 00 00 20 00       	test   $0x200000,%eax
  4017c6:	0f 84 e9 00 00 00    	je     4018b5 <___cpu_features_init+0x105>
  4017cc:	53                   	push   %ebx
  4017cd:	31 c0                	xor    %eax,%eax
  4017cf:	0f a2                	cpuid  
  4017d1:	85 c0                	test   %eax,%eax
  4017d3:	0f 84 db 00 00 00    	je     4018b4 <___cpu_features_init+0x104>
  4017d9:	b8 01 00 00 00       	mov    $0x1,%eax
  4017de:	0f a2                	cpuid  
  4017e0:	31 c0                	xor    %eax,%eax
  4017e2:	f6 c6 01             	test   $0x1,%dh
  4017e5:	74 03                	je     4017ea <___cpu_features_init+0x3a>
  4017e7:	83 c8 01             	or     $0x1,%eax
  4017ea:	f6 c5 20             	test   $0x20,%ch
  4017ed:	74 05                	je     4017f4 <___cpu_features_init+0x44>
  4017ef:	0d 80 00 00 00       	or     $0x80,%eax
  4017f4:	f6 c6 80             	test   $0x80,%dh
  4017f7:	74 03                	je     4017fc <___cpu_features_init+0x4c>
  4017f9:	83 c8 02             	or     $0x2,%eax
  4017fc:	f7 c2 00 00 80 00    	test   $0x800000,%edx
  401802:	74 03                	je     401807 <___cpu_features_init+0x57>
  401804:	83 c8 04             	or     $0x4,%eax
  401807:	f7 c2 00 00 00 01    	test   $0x1000000,%edx
  40180d:	74 6d                	je     40187c <___cpu_features_init+0xcc>
  40180f:	83 c8 08             	or     $0x8,%eax
  401812:	55                   	push   %ebp
  401813:	89 e5                	mov    %esp,%ebp
  401815:	81 ec 00 02 00 00    	sub    $0x200,%esp
  40181b:	83 e4 f0             	and    $0xfffffff0,%esp
  40181e:	0f ae 04 24          	fxsave (%esp)
  401822:	8b 9c 24 c8 00 00 00 	mov    0xc8(%esp),%ebx
  401829:	81 b4 24 c8 00 00 00 	xorl   $0x13c0de,0xc8(%esp)
  401830:	de c0 13 00 
  401834:	0f ae 0c 24          	fxrstor (%esp)
  401838:	89 9c 24 c8 00 00 00 	mov    %ebx,0xc8(%esp)
  40183f:	0f ae 04 24          	fxsave (%esp)
  401843:	87 9c 24 c8 00 00 00 	xchg   %ebx,0xc8(%esp)
  40184a:	0f ae 0c 24          	fxrstor (%esp)
  40184e:	33 9c 24 c8 00 00 00 	xor    0xc8(%esp),%ebx
  401855:	c9                   	leave  
  401856:	81 fb de c0 13 00    	cmp    $0x13c0de,%ebx
  40185c:	75 1e                	jne    40187c <___cpu_features_init+0xcc>
  40185e:	f7 c2 00 00 00 02    	test   $0x2000000,%edx
  401864:	74 03                	je     401869 <___cpu_features_init+0xb9>
  401866:	83 c8 10             	or     $0x10,%eax
  401869:	f7 c2 00 00 00 04    	test   $0x4000000,%edx
  40186f:	74 03                	je     401874 <___cpu_features_init+0xc4>
  401871:	83 c8 20             	or     $0x20,%eax
  401874:	f6 c1 01             	test   $0x1,%cl
  401877:	74 03                	je     40187c <___cpu_features_init+0xcc>
  401879:	83 c8 40             	or     $0x40,%eax
  40187c:	a3 24 70 40 00       	mov    %eax,0x407024
  401881:	b8 00 00 00 80       	mov    $0x80000000,%eax
  401886:	0f a2                	cpuid  
  401888:	3d 00 00 00 80       	cmp    $0x80000000,%eax
  40188d:	76 25                	jbe    4018b4 <___cpu_features_init+0x104>
  40188f:	b8 01 00 00 80       	mov    $0x80000001,%eax
  401894:	0f a2                	cpuid  
  401896:	31 c0                	xor    %eax,%eax
  401898:	85 d2                	test   %edx,%edx
  40189a:	79 05                	jns    4018a1 <___cpu_features_init+0xf1>
  40189c:	b8 00 01 00 00       	mov    $0x100,%eax
  4018a1:	f7 c2 00 00 00 40    	test   $0x40000000,%edx
  4018a7:	74 05                	je     4018ae <___cpu_features_init+0xfe>
  4018a9:	0d 00 02 00 00       	or     $0x200,%eax
  4018ae:	09 05 24 70 40 00    	or     %eax,0x407024
  4018b4:	5b                   	pop    %ebx
  4018b5:	f3 c3                	repz ret 
  4018b7:	90                   	nop
  4018b8:	90                   	nop
  4018b9:	90                   	nop
  4018ba:	90                   	nop
  4018bb:	90                   	nop
  4018bc:	90                   	nop
  4018bd:	90                   	nop
  4018be:	90                   	nop
  4018bf:	90                   	nop

004018c0 <___do_global_dtors>:
  4018c0:	a1 10 40 40 00       	mov    0x404010,%eax
  4018c5:	8b 00                	mov    (%eax),%eax
  4018c7:	85 c0                	test   %eax,%eax
  4018c9:	74 25                	je     4018f0 <___do_global_dtors+0x30>
  4018cb:	83 ec 0c             	sub    $0xc,%esp
  4018ce:	66 90                	xchg   %ax,%ax
  4018d0:	ff d0                	call   *%eax
  4018d2:	a1 10 40 40 00       	mov    0x404010,%eax
  4018d7:	8d 50 04             	lea    0x4(%eax),%edx
  4018da:	8b 40 04             	mov    0x4(%eax),%eax
  4018dd:	89 15 10 40 40 00    	mov    %edx,0x404010
  4018e3:	85 c0                	test   %eax,%eax
  4018e5:	75 e9                	jne    4018d0 <___do_global_dtors+0x10>
  4018e7:	83 c4 0c             	add    $0xc,%esp
  4018ea:	c3                   	ret    
  4018eb:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  4018ef:	90                   	nop
  4018f0:	c3                   	ret    
  4018f1:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  4018f8:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  4018ff:	90                   	nop

00401900 <___do_global_ctors>:
  401900:	53                   	push   %ebx
  401901:	83 ec 18             	sub    $0x18,%esp
  401904:	8b 1d 30 3f 40 00    	mov    0x403f30,%ebx
  40190a:	83 fb ff             	cmp    $0xffffffff,%ebx
  40190d:	74 29                	je     401938 <___do_global_ctors+0x38>
  40190f:	85 db                	test   %ebx,%ebx
  401911:	74 11                	je     401924 <___do_global_ctors+0x24>
  401913:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  401917:	90                   	nop
  401918:	ff 14 9d 30 3f 40 00 	call   *0x403f30(,%ebx,4)
  40191f:	83 eb 01             	sub    $0x1,%ebx
  401922:	75 f4                	jne    401918 <___do_global_ctors+0x18>
  401924:	c7 04 24 c0 18 40 00 	movl   $0x4018c0,(%esp)
  40192b:	e8 e0 f9 ff ff       	call   401310 <_atexit>
  401930:	83 c4 18             	add    $0x18,%esp
  401933:	5b                   	pop    %ebx
  401934:	c3                   	ret    
  401935:	8d 76 00             	lea    0x0(%esi),%esi
  401938:	31 c0                	xor    %eax,%eax
  40193a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  401940:	89 c3                	mov    %eax,%ebx
  401942:	83 c0 01             	add    $0x1,%eax
  401945:	8b 14 85 30 3f 40 00 	mov    0x403f30(,%eax,4),%edx
  40194c:	85 d2                	test   %edx,%edx
  40194e:	75 f0                	jne    401940 <___do_global_ctors+0x40>
  401950:	eb bd                	jmp    40190f <___do_global_ctors+0xf>
  401952:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  401959:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi

00401960 <___main>:
  401960:	a1 28 70 40 00       	mov    0x407028,%eax
  401965:	85 c0                	test   %eax,%eax
  401967:	74 07                	je     401970 <___main+0x10>
  401969:	c3                   	ret    
  40196a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  401970:	c7 05 28 70 40 00 01 	movl   $0x1,0x407028
  401977:	00 00 00 
  40197a:	eb 84                	jmp    401900 <___do_global_ctors>
  40197c:	90                   	nop
  40197d:	90                   	nop
  40197e:	90                   	nop
  40197f:	90                   	nop

00401980 <.text>:
  401980:	83 ec 1c             	sub    $0x1c,%esp
  401983:	8b 44 24 24          	mov    0x24(%esp),%eax
  401987:	83 f8 03             	cmp    $0x3,%eax
  40198a:	74 14                	je     4019a0 <.text+0x20>
  40198c:	85 c0                	test   %eax,%eax
  40198e:	74 10                	je     4019a0 <.text+0x20>
  401990:	b8 01 00 00 00       	mov    $0x1,%eax
  401995:	83 c4 1c             	add    $0x1c,%esp
  401998:	c2 0c 00             	ret    $0xc
  40199b:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  40199f:	90                   	nop
  4019a0:	89 44 24 04          	mov    %eax,0x4(%esp)
  4019a4:	8b 54 24 28          	mov    0x28(%esp),%edx
  4019a8:	8b 44 24 20          	mov    0x20(%esp),%eax
  4019ac:	89 54 24 08          	mov    %edx,0x8(%esp)
  4019b0:	89 04 24             	mov    %eax,(%esp)
  4019b3:	e8 48 02 00 00       	call   401c00 <___mingw_TLScallback>
  4019b8:	b8 01 00 00 00       	mov    $0x1,%eax
  4019bd:	83 c4 1c             	add    $0x1c,%esp
  4019c0:	c2 0c 00             	ret    $0xc
  4019c3:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  4019ca:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi

004019d0 <___dyn_tls_init@12>:
  4019d0:	56                   	push   %esi
  4019d1:	53                   	push   %ebx
  4019d2:	83 ec 14             	sub    $0x14,%esp
  4019d5:	83 3d 64 70 40 00 02 	cmpl   $0x2,0x407064
  4019dc:	8b 44 24 24          	mov    0x24(%esp),%eax
  4019e0:	74 0a                	je     4019ec <___dyn_tls_init@12+0x1c>
  4019e2:	c7 05 64 70 40 00 02 	movl   $0x2,0x407064
  4019e9:	00 00 00 
  4019ec:	83 f8 02             	cmp    $0x2,%eax
  4019ef:	74 17                	je     401a08 <___dyn_tls_init@12+0x38>
  4019f1:	83 f8 01             	cmp    $0x1,%eax
  4019f4:	74 52                	je     401a48 <___dyn_tls_init@12+0x78>
  4019f6:	83 c4 14             	add    $0x14,%esp
  4019f9:	b8 01 00 00 00       	mov    $0x1,%eax
  4019fe:	5b                   	pop    %ebx
  4019ff:	5e                   	pop    %esi
  401a00:	c2 0c 00             	ret    $0xc
  401a03:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  401a07:	90                   	nop
  401a08:	b8 14 90 40 00       	mov    $0x409014,%eax
  401a0d:	2d 14 90 40 00       	sub    $0x409014,%eax
  401a12:	89 c6                	mov    %eax,%esi
  401a14:	c1 fe 02             	sar    $0x2,%esi
  401a17:	85 c0                	test   %eax,%eax
  401a19:	7e db                	jle    4019f6 <___dyn_tls_init@12+0x26>
  401a1b:	31 db                	xor    %ebx,%ebx
  401a1d:	8d 76 00             	lea    0x0(%esi),%esi
  401a20:	8b 04 9d 14 90 40 00 	mov    0x409014(,%ebx,4),%eax
  401a27:	85 c0                	test   %eax,%eax
  401a29:	74 02                	je     401a2d <___dyn_tls_init@12+0x5d>
  401a2b:	ff d0                	call   *%eax
  401a2d:	83 c3 01             	add    $0x1,%ebx
  401a30:	39 de                	cmp    %ebx,%esi
  401a32:	7f ec                	jg     401a20 <___dyn_tls_init@12+0x50>
  401a34:	83 c4 14             	add    $0x14,%esp
  401a37:	b8 01 00 00 00       	mov    $0x1,%eax
  401a3c:	5b                   	pop    %ebx
  401a3d:	5e                   	pop    %esi
  401a3e:	c2 0c 00             	ret    $0xc
  401a41:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  401a48:	8b 44 24 28          	mov    0x28(%esp),%eax
  401a4c:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
  401a53:	00 
  401a54:	89 44 24 08          	mov    %eax,0x8(%esp)
  401a58:	8b 44 24 20          	mov    0x20(%esp),%eax
  401a5c:	89 04 24             	mov    %eax,(%esp)
  401a5f:	e8 9c 01 00 00       	call   401c00 <___mingw_TLScallback>
  401a64:	83 c4 14             	add    $0x14,%esp
  401a67:	b8 01 00 00 00       	mov    $0x1,%eax
  401a6c:	5b                   	pop    %ebx
  401a6d:	5e                   	pop    %esi
  401a6e:	c2 0c 00             	ret    $0xc
  401a71:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  401a78:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  401a7f:	90                   	nop

00401a80 <___tlregdtor>:
  401a80:	31 c0                	xor    %eax,%eax
  401a82:	c3                   	ret    
  401a83:	90                   	nop
  401a84:	90                   	nop
  401a85:	90                   	nop
  401a86:	90                   	nop
  401a87:	90                   	nop
  401a88:	90                   	nop
  401a89:	90                   	nop
  401a8a:	90                   	nop
  401a8b:	90                   	nop
  401a8c:	90                   	nop
  401a8d:	90                   	nop
  401a8e:	90                   	nop
  401a8f:	90                   	nop

00401a90 <.text>:
  401a90:	56                   	push   %esi
  401a91:	53                   	push   %ebx
  401a92:	83 ec 14             	sub    $0x14,%esp
  401a95:	c7 04 24 44 70 40 00 	movl   $0x407044,(%esp)
  401a9c:	e8 23 24 00 00       	call   403ec4 <_EnterCriticalSection@4>
  401aa1:	8b 1d 3c 70 40 00    	mov    0x40703c,%ebx
  401aa7:	83 ec 04             	sub    $0x4,%esp
  401aaa:	85 db                	test   %ebx,%ebx
  401aac:	74 2d                	je     401adb <.text+0x4b>
  401aae:	66 90                	xchg   %ax,%ax
  401ab0:	8b 03                	mov    (%ebx),%eax
  401ab2:	89 04 24             	mov    %eax,(%esp)
  401ab5:	e8 9a 23 00 00       	call   403e54 <_TlsGetValue@4>
  401aba:	83 ec 04             	sub    $0x4,%esp
  401abd:	89 c6                	mov    %eax,%esi
  401abf:	e8 c8 23 00 00       	call   403e8c <_GetLastError@0>
  401ac4:	85 c0                	test   %eax,%eax
  401ac6:	75 0c                	jne    401ad4 <.text+0x44>
  401ac8:	85 f6                	test   %esi,%esi
  401aca:	74 08                	je     401ad4 <.text+0x44>
  401acc:	8b 43 04             	mov    0x4(%ebx),%eax
  401acf:	89 34 24             	mov    %esi,(%esp)
  401ad2:	ff d0                	call   *%eax
  401ad4:	8b 5b 08             	mov    0x8(%ebx),%ebx
  401ad7:	85 db                	test   %ebx,%ebx
  401ad9:	75 d5                	jne    401ab0 <.text+0x20>
  401adb:	c7 04 24 44 70 40 00 	movl   $0x407044,(%esp)
  401ae2:	e8 85 23 00 00       	call   403e6c <_LeaveCriticalSection@4>
  401ae7:	83 ec 04             	sub    $0x4,%esp
  401aea:	83 c4 14             	add    $0x14,%esp
  401aed:	5b                   	pop    %ebx
  401aee:	5e                   	pop    %esi
  401aef:	c3                   	ret    

00401af0 <____w64_mingwthr_add_key_dtor>:
  401af0:	a1 40 70 40 00       	mov    0x407040,%eax
  401af5:	85 c0                	test   %eax,%eax
  401af7:	75 07                	jne    401b00 <____w64_mingwthr_add_key_dtor+0x10>
  401af9:	c3                   	ret    
  401afa:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  401b00:	53                   	push   %ebx
  401b01:	83 ec 18             	sub    $0x18,%esp
  401b04:	c7 44 24 04 0c 00 00 	movl   $0xc,0x4(%esp)
  401b0b:	00 
  401b0c:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
  401b13:	e8 cc 22 00 00       	call   403de4 <_calloc>
  401b18:	89 c3                	mov    %eax,%ebx
  401b1a:	85 c0                	test   %eax,%eax
  401b1c:	74 40                	je     401b5e <____w64_mingwthr_add_key_dtor+0x6e>
  401b1e:	8b 44 24 20          	mov    0x20(%esp),%eax
  401b22:	c7 04 24 44 70 40 00 	movl   $0x407044,(%esp)
  401b29:	89 03                	mov    %eax,(%ebx)
  401b2b:	8b 44 24 24          	mov    0x24(%esp),%eax
  401b2f:	89 43 04             	mov    %eax,0x4(%ebx)
  401b32:	e8 8d 23 00 00       	call   403ec4 <_EnterCriticalSection@4>
  401b37:	a1 3c 70 40 00       	mov    0x40703c,%eax
  401b3c:	89 1d 3c 70 40 00    	mov    %ebx,0x40703c
  401b42:	83 ec 04             	sub    $0x4,%esp
  401b45:	c7 04 24 44 70 40 00 	movl   $0x407044,(%esp)
  401b4c:	89 43 08             	mov    %eax,0x8(%ebx)
  401b4f:	e8 18 23 00 00       	call   403e6c <_LeaveCriticalSection@4>
  401b54:	31 c0                	xor    %eax,%eax
  401b56:	83 ec 04             	sub    $0x4,%esp
  401b59:	83 c4 18             	add    $0x18,%esp
  401b5c:	5b                   	pop    %ebx
  401b5d:	c3                   	ret    
  401b5e:	83 c8 ff             	or     $0xffffffff,%eax
  401b61:	eb f6                	jmp    401b59 <____w64_mingwthr_add_key_dtor+0x69>
  401b63:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  401b6a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi

00401b70 <____w64_mingwthr_remove_key_dtor>:
  401b70:	53                   	push   %ebx
  401b71:	83 ec 18             	sub    $0x18,%esp
  401b74:	a1 40 70 40 00       	mov    0x407040,%eax
  401b79:	8b 5c 24 20          	mov    0x20(%esp),%ebx
  401b7d:	85 c0                	test   %eax,%eax
  401b7f:	75 0f                	jne    401b90 <____w64_mingwthr_remove_key_dtor+0x20>
  401b81:	83 c4 18             	add    $0x18,%esp
  401b84:	31 c0                	xor    %eax,%eax
  401b86:	5b                   	pop    %ebx
  401b87:	c3                   	ret    
  401b88:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  401b8f:	90                   	nop
  401b90:	c7 04 24 44 70 40 00 	movl   $0x407044,(%esp)
  401b97:	e8 28 23 00 00       	call   403ec4 <_EnterCriticalSection@4>
  401b9c:	a1 3c 70 40 00       	mov    0x40703c,%eax
  401ba1:	83 ec 04             	sub    $0x4,%esp
  401ba4:	85 c0                	test   %eax,%eax
  401ba6:	74 28                	je     401bd0 <____w64_mingwthr_remove_key_dtor+0x60>
  401ba8:	31 c9                	xor    %ecx,%ecx
  401baa:	eb 0c                	jmp    401bb8 <____w64_mingwthr_remove_key_dtor+0x48>
  401bac:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  401bb0:	89 c1                	mov    %eax,%ecx
  401bb2:	85 d2                	test   %edx,%edx
  401bb4:	74 1a                	je     401bd0 <____w64_mingwthr_remove_key_dtor+0x60>
  401bb6:	89 d0                	mov    %edx,%eax
  401bb8:	8b 10                	mov    (%eax),%edx
  401bba:	39 da                	cmp    %ebx,%edx
  401bbc:	8b 50 08             	mov    0x8(%eax),%edx
  401bbf:	75 ef                	jne    401bb0 <____w64_mingwthr_remove_key_dtor+0x40>
  401bc1:	85 c9                	test   %ecx,%ecx
  401bc3:	74 2b                	je     401bf0 <____w64_mingwthr_remove_key_dtor+0x80>
  401bc5:	89 51 08             	mov    %edx,0x8(%ecx)
  401bc8:	89 04 24             	mov    %eax,(%esp)
  401bcb:	e8 a0 04 00 00       	call   402070 <___mingw_aligned_free>
  401bd0:	c7 04 24 44 70 40 00 	movl   $0x407044,(%esp)
  401bd7:	e8 90 22 00 00       	call   403e6c <_LeaveCriticalSection@4>
  401bdc:	31 c0                	xor    %eax,%eax
  401bde:	83 ec 04             	sub    $0x4,%esp
  401be1:	83 c4 18             	add    $0x18,%esp
  401be4:	5b                   	pop    %ebx
  401be5:	c3                   	ret    
  401be6:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  401bed:	8d 76 00             	lea    0x0(%esi),%esi
  401bf0:	89 15 3c 70 40 00    	mov    %edx,0x40703c
  401bf6:	eb d0                	jmp    401bc8 <____w64_mingwthr_remove_key_dtor+0x58>
  401bf8:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  401bff:	90                   	nop

00401c00 <___mingw_TLScallback>:
  401c00:	83 ec 1c             	sub    $0x1c,%esp
  401c03:	8b 44 24 24          	mov    0x24(%esp),%eax
  401c07:	83 f8 01             	cmp    $0x1,%eax
  401c0a:	74 14                	je     401c20 <___mingw_TLScallback+0x20>
  401c0c:	83 f8 03             	cmp    $0x3,%eax
  401c0f:	74 5f                	je     401c70 <___mingw_TLScallback+0x70>
  401c11:	85 c0                	test   %eax,%eax
  401c13:	74 2b                	je     401c40 <___mingw_TLScallback+0x40>
  401c15:	b8 01 00 00 00       	mov    $0x1,%eax
  401c1a:	83 c4 1c             	add    $0x1c,%esp
  401c1d:	c3                   	ret    
  401c1e:	66 90                	xchg   %ax,%ax
  401c20:	a1 40 70 40 00       	mov    0x407040,%eax
  401c25:	85 c0                	test   %eax,%eax
  401c27:	74 7f                	je     401ca8 <___mingw_TLScallback+0xa8>
  401c29:	c7 05 40 70 40 00 01 	movl   $0x1,0x407040
  401c30:	00 00 00 
  401c33:	b8 01 00 00 00       	mov    $0x1,%eax
  401c38:	83 c4 1c             	add    $0x1c,%esp
  401c3b:	c3                   	ret    
  401c3c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  401c40:	a1 40 70 40 00       	mov    0x407040,%eax
  401c45:	85 c0                	test   %eax,%eax
  401c47:	75 47                	jne    401c90 <___mingw_TLScallback+0x90>
  401c49:	a1 40 70 40 00       	mov    0x407040,%eax
  401c4e:	83 f8 01             	cmp    $0x1,%eax
  401c51:	75 c2                	jne    401c15 <___mingw_TLScallback+0x15>
  401c53:	c7 04 24 44 70 40 00 	movl   $0x407044,(%esp)
  401c5a:	c7 05 40 70 40 00 00 	movl   $0x0,0x407040
  401c61:	00 00 00 
  401c64:	e8 63 22 00 00       	call   403ecc <_DeleteCriticalSection@4>
  401c69:	83 ec 04             	sub    $0x4,%esp
  401c6c:	eb a7                	jmp    401c15 <___mingw_TLScallback+0x15>
  401c6e:	66 90                	xchg   %ax,%ax
  401c70:	a1 40 70 40 00       	mov    0x407040,%eax
  401c75:	85 c0                	test   %eax,%eax
  401c77:	74 9c                	je     401c15 <___mingw_TLScallback+0x15>
  401c79:	e8 12 fe ff ff       	call   401a90 <.text>
  401c7e:	b8 01 00 00 00       	mov    $0x1,%eax
  401c83:	83 c4 1c             	add    $0x1c,%esp
  401c86:	c3                   	ret    
  401c87:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  401c8e:	66 90                	xchg   %ax,%ax
  401c90:	e8 fb fd ff ff       	call   401a90 <.text>
  401c95:	a1 40 70 40 00       	mov    0x407040,%eax
  401c9a:	83 f8 01             	cmp    $0x1,%eax
  401c9d:	0f 85 72 ff ff ff    	jne    401c15 <___mingw_TLScallback+0x15>
  401ca3:	eb ae                	jmp    401c53 <___mingw_TLScallback+0x53>
  401ca5:	8d 76 00             	lea    0x0(%esi),%esi
  401ca8:	c7 04 24 44 70 40 00 	movl   $0x407044,(%esp)
  401caf:	e8 c0 21 00 00       	call   403e74 <_InitializeCriticalSection@4>
  401cb4:	83 ec 04             	sub    $0x4,%esp
  401cb7:	e9 6d ff ff ff       	jmp    401c29 <___mingw_TLScallback+0x29>
  401cbc:	90                   	nop
  401cbd:	90                   	nop
  401cbe:	90                   	nop
  401cbf:	90                   	nop

00401cc0 <.text>:
  401cc0:	56                   	push   %esi
  401cc1:	53                   	push   %ebx
  401cc2:	83 ec 14             	sub    $0x14,%esp
  401cc5:	a1 b0 81 40 00       	mov    0x4081b0,%eax
  401cca:	c7 44 24 08 17 00 00 	movl   $0x17,0x8(%esp)
  401cd1:	00 
  401cd2:	8d 74 24 24          	lea    0x24(%esp),%esi
  401cd6:	8d 58 40             	lea    0x40(%eax),%ebx
  401cd9:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
  401ce0:	00 
  401ce1:	89 5c 24 0c          	mov    %ebx,0xc(%esp)
  401ce5:	c7 04 24 58 51 40 00 	movl   $0x405158,(%esp)
  401cec:	e8 eb 20 00 00       	call   403ddc <_fwrite>
  401cf1:	8b 44 24 20          	mov    0x20(%esp),%eax
  401cf5:	89 74 24 08          	mov    %esi,0x8(%esp)
  401cf9:	89 1c 24             	mov    %ebx,(%esp)
  401cfc:	89 44 24 04          	mov    %eax,0x4(%esp)
  401d00:	e8 7f 20 00 00       	call   403d84 <_vfprintf>
  401d05:	e8 ea 20 00 00       	call   403df4 <_abort>
  401d0a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  401d10:	55                   	push   %ebp
  401d11:	57                   	push   %edi
  401d12:	89 d7                	mov    %edx,%edi
  401d14:	56                   	push   %esi
  401d15:	89 ce                	mov    %ecx,%esi
  401d17:	53                   	push   %ebx
  401d18:	89 c3                	mov    %eax,%ebx
  401d1a:	83 ec 3c             	sub    $0x3c,%esp
  401d1d:	8d 44 24 14          	lea    0x14(%esp),%eax
  401d21:	c7 44 24 08 1c 00 00 	movl   $0x1c,0x8(%esp)
  401d28:	00 
  401d29:	89 44 24 04          	mov    %eax,0x4(%esp)
  401d2d:	89 1c 24             	mov    %ebx,(%esp)
  401d30:	e8 0f 21 00 00       	call   403e44 <_VirtualQuery@12>
  401d35:	83 ec 0c             	sub    $0xc,%esp
  401d38:	85 c0                	test   %eax,%eax
  401d3a:	0f 84 a4 00 00 00    	je     401de4 <.text+0x124>
  401d40:	8b 44 24 28          	mov    0x28(%esp),%eax
  401d44:	83 f8 40             	cmp    $0x40,%eax
  401d47:	74 05                	je     401d4e <.text+0x8e>
  401d49:	83 f8 04             	cmp    $0x4,%eax
  401d4c:	75 22                	jne    401d70 <.text+0xb0>
  401d4e:	85 f6                	test   %esi,%esi
  401d50:	74 10                	je     401d62 <.text+0xa2>
  401d52:	31 c0                	xor    %eax,%eax
  401d54:	0f b6 0c 07          	movzbl (%edi,%eax,1),%ecx
  401d58:	88 0c 03             	mov    %cl,(%ebx,%eax,1)
  401d5b:	83 c0 01             	add    $0x1,%eax
  401d5e:	39 f0                	cmp    %esi,%eax
  401d60:	72 f2                	jb     401d54 <.text+0x94>
  401d62:	83 c4 3c             	add    $0x3c,%esp
  401d65:	5b                   	pop    %ebx
  401d66:	5e                   	pop    %esi
  401d67:	5f                   	pop    %edi
  401d68:	5d                   	pop    %ebp
  401d69:	c3                   	ret    
  401d6a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  401d70:	8b 44 24 20          	mov    0x20(%esp),%eax
  401d74:	8d 6c 24 10          	lea    0x10(%esp),%ebp
  401d78:	c7 44 24 08 40 00 00 	movl   $0x40,0x8(%esp)
  401d7f:	00 
  401d80:	89 6c 24 0c          	mov    %ebp,0xc(%esp)
  401d84:	89 44 24 04          	mov    %eax,0x4(%esp)
  401d88:	8b 44 24 14          	mov    0x14(%esp),%eax
  401d8c:	89 04 24             	mov    %eax,(%esp)
  401d8f:	e8 b8 20 00 00       	call   403e4c <_VirtualProtect@16>
  401d94:	83 ec 10             	sub    $0x10,%esp
  401d97:	8b 4c 24 28          	mov    0x28(%esp),%ecx
  401d9b:	85 f6                	test   %esi,%esi
  401d9d:	74 10                	je     401daf <.text+0xef>
  401d9f:	31 d2                	xor    %edx,%edx
  401da1:	0f b6 04 17          	movzbl (%edi,%edx,1),%eax
  401da5:	88 04 13             	mov    %al,(%ebx,%edx,1)
  401da8:	83 c2 01             	add    $0x1,%edx
  401dab:	39 f2                	cmp    %esi,%edx
  401dad:	72 f2                	jb     401da1 <.text+0xe1>
  401daf:	83 f9 40             	cmp    $0x40,%ecx
  401db2:	74 ae                	je     401d62 <.text+0xa2>
  401db4:	83 f9 04             	cmp    $0x4,%ecx
  401db7:	74 a9                	je     401d62 <.text+0xa2>
  401db9:	8b 44 24 10          	mov    0x10(%esp),%eax
  401dbd:	89 6c 24 0c          	mov    %ebp,0xc(%esp)
  401dc1:	89 44 24 08          	mov    %eax,0x8(%esp)
  401dc5:	8b 44 24 20          	mov    0x20(%esp),%eax
  401dc9:	89 44 24 04          	mov    %eax,0x4(%esp)
  401dcd:	8b 44 24 14          	mov    0x14(%esp),%eax
  401dd1:	89 04 24             	mov    %eax,(%esp)
  401dd4:	e8 73 20 00 00       	call   403e4c <_VirtualProtect@16>
  401dd9:	83 ec 10             	sub    $0x10,%esp
  401ddc:	83 c4 3c             	add    $0x3c,%esp
  401ddf:	5b                   	pop    %ebx
  401de0:	5e                   	pop    %esi
  401de1:	5f                   	pop    %edi
  401de2:	5d                   	pop    %ebp
  401de3:	c3                   	ret    
  401de4:	89 5c 24 08          	mov    %ebx,0x8(%esp)
  401de8:	c7 44 24 04 1c 00 00 	movl   $0x1c,0x4(%esp)
  401def:	00 
  401df0:	c7 04 24 70 51 40 00 	movl   $0x405170,(%esp)
  401df7:	e8 c4 fe ff ff       	call   401cc0 <.text>
  401dfc:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi

00401e00 <__pei386_runtime_relocator>:
  401e00:	a1 5c 70 40 00       	mov    0x40705c,%eax
  401e05:	85 c0                	test   %eax,%eax
  401e07:	74 07                	je     401e10 <__pei386_runtime_relocator+0x10>
  401e09:	c3                   	ret    
  401e0a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  401e10:	c7 05 5c 70 40 00 01 	movl   $0x1,0x40705c
  401e17:	00 00 00 
  401e1a:	b8 24 57 40 00       	mov    $0x405724,%eax
  401e1f:	2d 24 57 40 00       	sub    $0x405724,%eax
  401e24:	83 f8 07             	cmp    $0x7,%eax
  401e27:	7e e0                	jle    401e09 <__pei386_runtime_relocator+0x9>
  401e29:	57                   	push   %edi
  401e2a:	56                   	push   %esi
  401e2b:	53                   	push   %ebx
  401e2c:	83 ec 20             	sub    $0x20,%esp
  401e2f:	8b 15 24 57 40 00    	mov    0x405724,%edx
  401e35:	83 f8 0b             	cmp    $0xb,%eax
  401e38:	0f 8f 92 00 00 00    	jg     401ed0 <__pei386_runtime_relocator+0xd0>
  401e3e:	bb 24 57 40 00       	mov    $0x405724,%ebx
  401e43:	85 d2                	test   %edx,%edx
  401e45:	0f 85 3a 01 00 00    	jne    401f85 <__pei386_runtime_relocator+0x185>
  401e4b:	8b 43 04             	mov    0x4(%ebx),%eax
  401e4e:	85 c0                	test   %eax,%eax
  401e50:	0f 85 2f 01 00 00    	jne    401f85 <__pei386_runtime_relocator+0x185>
  401e56:	8b 43 08             	mov    0x8(%ebx),%eax
  401e59:	83 f8 01             	cmp    $0x1,%eax
  401e5c:	0f 85 78 01 00 00    	jne    401fda <__pei386_runtime_relocator+0x1da>
  401e62:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  401e68:	83 c3 0c             	add    $0xc,%ebx
  401e6b:	81 fb 24 57 40 00    	cmp    $0x405724,%ebx
  401e71:	73 4c                	jae    401ebf <__pei386_runtime_relocator+0xbf>
  401e73:	8b 03                	mov    (%ebx),%eax
  401e75:	8b 4b 04             	mov    0x4(%ebx),%ecx
  401e78:	0f b6 53 08          	movzbl 0x8(%ebx),%edx
  401e7c:	8d b8 00 00 40 00    	lea    0x400000(%eax),%edi
  401e82:	8d b1 00 00 40 00    	lea    0x400000(%ecx),%esi
  401e88:	8b 80 00 00 40 00    	mov    0x400000(%eax),%eax
  401e8e:	83 fa 10             	cmp    $0x10,%edx
  401e91:	0f 84 89 00 00 00    	je     401f20 <__pei386_runtime_relocator+0x120>
  401e97:	83 fa 20             	cmp    $0x20,%edx
  401e9a:	75 64                	jne    401f00 <__pei386_runtime_relocator+0x100>
  401e9c:	29 f8                	sub    %edi,%eax
  401e9e:	03 06                	add    (%esi),%eax
  401ea0:	b9 04 00 00 00       	mov    $0x4,%ecx
  401ea5:	83 c3 0c             	add    $0xc,%ebx
  401ea8:	89 44 24 1c          	mov    %eax,0x1c(%esp)
  401eac:	8d 54 24 1c          	lea    0x1c(%esp),%edx
  401eb0:	89 f0                	mov    %esi,%eax
  401eb2:	e8 59 fe ff ff       	call   401d10 <.text+0x50>
  401eb7:	81 fb 24 57 40 00    	cmp    $0x405724,%ebx
  401ebd:	72 b4                	jb     401e73 <__pei386_runtime_relocator+0x73>
  401ebf:	83 c4 20             	add    $0x20,%esp
  401ec2:	5b                   	pop    %ebx
  401ec3:	5e                   	pop    %esi
  401ec4:	5f                   	pop    %edi
  401ec5:	c3                   	ret    
  401ec6:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  401ecd:	8d 76 00             	lea    0x0(%esi),%esi
  401ed0:	85 d2                	test   %edx,%edx
  401ed2:	0f 85 a8 00 00 00    	jne    401f80 <__pei386_runtime_relocator+0x180>
  401ed8:	a1 28 57 40 00       	mov    0x405728,%eax
  401edd:	89 c7                	mov    %eax,%edi
  401edf:	0b 3d 2c 57 40 00    	or     0x40572c,%edi
  401ee5:	0f 85 e5 00 00 00    	jne    401fd0 <__pei386_runtime_relocator+0x1d0>
  401eeb:	8b 15 30 57 40 00    	mov    0x405730,%edx
  401ef1:	bb 30 57 40 00       	mov    $0x405730,%ebx
  401ef6:	e9 48 ff ff ff       	jmp    401e43 <__pei386_runtime_relocator+0x43>
  401efb:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  401eff:	90                   	nop
  401f00:	83 fa 08             	cmp    $0x8,%edx
  401f03:	74 4b                	je     401f50 <__pei386_runtime_relocator+0x150>
  401f05:	89 54 24 04          	mov    %edx,0x4(%esp)
  401f09:	c7 04 24 d8 51 40 00 	movl   $0x4051d8,(%esp)
  401f10:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%esp)
  401f17:	00 
  401f18:	e8 a3 fd ff ff       	call   401cc0 <.text>
  401f1d:	8d 76 00             	lea    0x0(%esi),%esi
  401f20:	0f b7 91 00 00 40 00 	movzwl 0x400000(%ecx),%edx
  401f27:	66 85 d2             	test   %dx,%dx
  401f2a:	79 06                	jns    401f32 <__pei386_runtime_relocator+0x132>
  401f2c:	81 ca 00 00 ff ff    	or     $0xffff0000,%edx
  401f32:	29 fa                	sub    %edi,%edx
  401f34:	b9 02 00 00 00       	mov    $0x2,%ecx
  401f39:	01 d0                	add    %edx,%eax
  401f3b:	8d 54 24 1c          	lea    0x1c(%esp),%edx
  401f3f:	89 44 24 1c          	mov    %eax,0x1c(%esp)
  401f43:	89 f0                	mov    %esi,%eax
  401f45:	e8 c6 fd ff ff       	call   401d10 <.text+0x50>
  401f4a:	e9 19 ff ff ff       	jmp    401e68 <__pei386_runtime_relocator+0x68>
  401f4f:	90                   	nop
  401f50:	0f b6 0e             	movzbl (%esi),%ecx
  401f53:	84 c9                	test   %cl,%cl
  401f55:	79 06                	jns    401f5d <__pei386_runtime_relocator+0x15d>
  401f57:	81 c9 00 ff ff ff    	or     $0xffffff00,%ecx
  401f5d:	29 f9                	sub    %edi,%ecx
  401f5f:	8d 54 24 1c          	lea    0x1c(%esp),%edx
  401f63:	01 c8                	add    %ecx,%eax
  401f65:	b9 01 00 00 00       	mov    $0x1,%ecx
  401f6a:	89 44 24 1c          	mov    %eax,0x1c(%esp)
  401f6e:	89 f0                	mov    %esi,%eax
  401f70:	e8 9b fd ff ff       	call   401d10 <.text+0x50>
  401f75:	e9 ee fe ff ff       	jmp    401e68 <__pei386_runtime_relocator+0x68>
  401f7a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  401f80:	bb 24 57 40 00       	mov    $0x405724,%ebx
  401f85:	81 fb 24 57 40 00    	cmp    $0x405724,%ebx
  401f8b:	0f 83 2e ff ff ff    	jae    401ebf <__pei386_runtime_relocator+0xbf>
  401f91:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  401f98:	8b 53 04             	mov    0x4(%ebx),%edx
  401f9b:	8b 03                	mov    (%ebx),%eax
  401f9d:	b9 04 00 00 00       	mov    $0x4,%ecx
  401fa2:	83 c3 08             	add    $0x8,%ebx
  401fa5:	03 82 00 00 40 00    	add    0x400000(%edx),%eax
  401fab:	8d b2 00 00 40 00    	lea    0x400000(%edx),%esi
  401fb1:	8d 54 24 1c          	lea    0x1c(%esp),%edx
  401fb5:	89 44 24 1c          	mov    %eax,0x1c(%esp)
  401fb9:	89 f0                	mov    %esi,%eax
  401fbb:	e8 50 fd ff ff       	call   401d10 <.text+0x50>
  401fc0:	81 fb 24 57 40 00    	cmp    $0x405724,%ebx
  401fc6:	72 d0                	jb     401f98 <__pei386_runtime_relocator+0x198>
  401fc8:	83 c4 20             	add    $0x20,%esp
  401fcb:	5b                   	pop    %ebx
  401fcc:	5e                   	pop    %esi
  401fcd:	5f                   	pop    %edi
  401fce:	c3                   	ret    
  401fcf:	90                   	nop
  401fd0:	bb 24 57 40 00       	mov    $0x405724,%ebx
  401fd5:	e9 74 fe ff ff       	jmp    401e4e <__pei386_runtime_relocator+0x4e>
  401fda:	89 44 24 04          	mov    %eax,0x4(%esp)
  401fde:	c7 04 24 a4 51 40 00 	movl   $0x4051a4,(%esp)
  401fe5:	e8 d6 fc ff ff       	call   401cc0 <.text>
  401fea:	90                   	nop
  401feb:	90                   	nop
  401fec:	90                   	nop
  401fed:	90                   	nop
  401fee:	90                   	nop
  401fef:	90                   	nop

00401ff0 <_fesetenv>:
  401ff0:	83 ec 1c             	sub    $0x1c,%esp
  401ff3:	8b 44 24 20          	mov    0x20(%esp),%eax
  401ff7:	c7 44 24 0c 80 1f 00 	movl   $0x1f80,0xc(%esp)
  401ffe:	00 
  401fff:	83 f8 fd             	cmp    $0xfffffffd,%eax
  402002:	74 4c                	je     402050 <_fesetenv+0x60>
  402004:	83 f8 fc             	cmp    $0xfffffffc,%eax
  402007:	74 2f                	je     402038 <_fesetenv+0x48>
  402009:	85 c0                	test   %eax,%eax
  40200b:	74 53                	je     402060 <_fesetenv+0x70>
  40200d:	83 f8 ff             	cmp    $0xffffffff,%eax
  402010:	74 48                	je     40205a <_fesetenv+0x6a>
  402012:	83 f8 fe             	cmp    $0xfffffffe,%eax
  402015:	74 2b                	je     402042 <_fesetenv+0x52>
  402017:	d9 20                	fldenv (%eax)
  402019:	0f b7 40 1c          	movzwl 0x1c(%eax),%eax
  40201d:	89 44 24 0c          	mov    %eax,0xc(%esp)
  402021:	f6 05 24 70 40 00 10 	testb  $0x10,0x407024
  402028:	74 05                	je     40202f <_fesetenv+0x3f>
  40202a:	0f ae 54 24 0c       	ldmxcsr 0xc(%esp)
  40202f:	31 c0                	xor    %eax,%eax
  402031:	83 c4 1c             	add    $0x1c,%esp
  402034:	c3                   	ret    
  402035:	8d 76 00             	lea    0x0(%esi),%esi
  402038:	c7 05 14 40 40 00 fe 	movl   $0xfffffffe,0x404014
  40203f:	ff ff ff 
  402042:	ff 15 a8 81 40 00    	call   *0x4081a8
  402048:	eb d7                	jmp    402021 <_fesetenv+0x31>
  40204a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  402050:	c7 05 14 40 40 00 ff 	movl   $0xffffffff,0x404014
  402057:	ff ff ff 
  40205a:	db e3                	fninit 
  40205c:	eb c3                	jmp    402021 <_fesetenv+0x31>
  40205e:	66 90                	xchg   %ax,%ax
  402060:	a1 14 40 40 00       	mov    0x404014,%eax
  402065:	eb a6                	jmp    40200d <_fesetenv+0x1d>
  402067:	90                   	nop
  402068:	90                   	nop
  402069:	90                   	nop
  40206a:	90                   	nop
  40206b:	90                   	nop
  40206c:	90                   	nop
  40206d:	90                   	nop
  40206e:	90                   	nop
  40206f:	90                   	nop

00402070 <___mingw_aligned_free>:
  402070:	83 ec 2c             	sub    $0x2c,%esp
  402073:	8d 44 24 10          	lea    0x10(%esp),%eax
  402077:	89 44 24 04          	mov    %eax,0x4(%esp)
  40207b:	8b 44 24 30          	mov    0x30(%esp),%eax
  40207f:	89 04 24             	mov    %eax,(%esp)
  402082:	e8 99 1a 00 00       	call   403b20 <___mingw_memalign_base>
  402087:	89 04 24             	mov    %eax,(%esp)
  40208a:	ff 15 0c 82 40 00    	call   *0x40820c
  402090:	83 c4 2c             	add    $0x2c,%esp
  402093:	c3                   	ret    
  402094:	90                   	nop
  402095:	90                   	nop
  402096:	90                   	nop
  402097:	90                   	nop
  402098:	90                   	nop
  402099:	90                   	nop
  40209a:	90                   	nop
  40209b:	90                   	nop
  40209c:	90                   	nop
  40209d:	90                   	nop
  40209e:	90                   	nop
  40209f:	90                   	nop

004020a0 <.text>:
  4020a0:	55                   	push   %ebp
  4020a1:	57                   	push   %edi
  4020a2:	56                   	push   %esi
  4020a3:	53                   	push   %ebx
  4020a4:	83 ec 3c             	sub    $0x3c,%esp
  4020a7:	0f be 28             	movsbl (%eax),%ebp
  4020aa:	89 54 24 1c          	mov    %edx,0x1c(%esp)
  4020ae:	89 4c 24 28          	mov    %ecx,0x28(%esp)
  4020b2:	89 eb                	mov    %ebp,%ebx
  4020b4:	83 fd 2d             	cmp    $0x2d,%ebp
  4020b7:	0f 84 db 00 00 00    	je     402198 <.text+0xf8>
  4020bd:	89 c2                	mov    %eax,%edx
  4020bf:	83 fd 5d             	cmp    $0x5d,%ebp
  4020c2:	0f 84 d0 00 00 00    	je     402198 <.text+0xf8>
  4020c8:	8b 44 24 28          	mov    0x28(%esp),%eax
  4020cc:	25 00 40 00 00       	and    $0x4000,%eax
  4020d1:	89 44 24 20          	mov    %eax,0x20(%esp)
  4020d5:	89 e8                	mov    %ebp,%eax
  4020d7:	89 d5                	mov    %edx,%ebp
  4020d9:	89 da                	mov    %ebx,%edx
  4020db:	89 c3                	mov    %eax,%ebx
  4020dd:	eb 0b                	jmp    4020ea <.text+0x4a>
  4020df:	90                   	nop
  4020e0:	89 d6                	mov    %edx,%esi
  4020e2:	2b 74 24 1c          	sub    0x1c(%esp),%esi
  4020e6:	85 f6                	test   %esi,%esi
  4020e8:	74 64                	je     40214e <.text+0xae>
  4020ea:	8d 7d 01             	lea    0x1(%ebp),%edi
  4020ed:	89 de                	mov    %ebx,%esi
  4020ef:	83 fb 5d             	cmp    $0x5d,%ebx
  4020f2:	0f 84 d0 00 00 00    	je     4021c8 <.text+0x128>
  4020f8:	83 fb 2d             	cmp    $0x2d,%ebx
  4020fb:	0f 84 b7 00 00 00    	je     4021b8 <.text+0x118>
  402101:	85 db                	test   %ebx,%ebx
  402103:	0f 84 bf 00 00 00    	je     4021c8 <.text+0x128>
  402109:	83 fe 2f             	cmp    $0x2f,%esi
  40210c:	0f 84 b6 00 00 00    	je     4021c8 <.text+0x128>
  402112:	83 fe 5c             	cmp    $0x5c,%esi
  402115:	0f 84 ad 00 00 00    	je     4021c8 <.text+0x128>
  40211b:	0f be 1f             	movsbl (%edi),%ebx
  40211e:	89 fd                	mov    %edi,%ebp
  402120:	89 f2                	mov    %esi,%edx
  402122:	8b 44 24 20          	mov    0x20(%esp),%eax
  402126:	85 c0                	test   %eax,%eax
  402128:	75 b6                	jne    4020e0 <.text+0x40>
  40212a:	89 14 24             	mov    %edx,(%esp)
  40212d:	89 54 24 24          	mov    %edx,0x24(%esp)
  402131:	e8 56 1c 00 00       	call   403d8c <_tolower>
  402136:	89 c6                	mov    %eax,%esi
  402138:	8b 44 24 1c          	mov    0x1c(%esp),%eax
  40213c:	89 04 24             	mov    %eax,(%esp)
  40213f:	e8 48 1c 00 00       	call   403d8c <_tolower>
  402144:	8b 54 24 24          	mov    0x24(%esp),%edx
  402148:	29 c6                	sub    %eax,%esi
  40214a:	85 f6                	test   %esi,%esi
  40214c:	75 9c                	jne    4020ea <.text+0x4a>
  40214e:	89 d9                	mov    %ebx,%ecx
  402150:	8b 5c 24 28          	mov    0x28(%esp),%ebx
  402154:	89 ea                	mov    %ebp,%edx
  402156:	83 e3 20             	and    $0x20,%ebx
  402159:	8d 42 01             	lea    0x1(%edx),%eax
  40215c:	80 f9 5d             	cmp    $0x5d,%cl
  40215f:	74 69                	je     4021ca <.text+0x12a>
  402161:	80 f9 7f             	cmp    $0x7f,%cl
  402164:	74 17                	je     40217d <.text+0xdd>
  402166:	84 c9                	test   %cl,%cl
  402168:	74 5e                	je     4021c8 <.text+0x128>
  40216a:	0f b6 4a 01          	movzbl 0x1(%edx),%ecx
  40216e:	89 c2                	mov    %eax,%edx
  402170:	8d 42 01             	lea    0x1(%edx),%eax
  402173:	80 f9 5d             	cmp    $0x5d,%cl
  402176:	74 52                	je     4021ca <.text+0x12a>
  402178:	80 f9 7f             	cmp    $0x7f,%cl
  40217b:	75 e9                	jne    402166 <.text+0xc6>
  40217d:	0f b6 4a 01          	movzbl 0x1(%edx),%ecx
  402181:	85 db                	test   %ebx,%ebx
  402183:	0f 85 1f 02 00 00    	jne    4023a8 <.text+0x308>
  402189:	8d 72 02             	lea    0x2(%edx),%esi
  40218c:	89 c2                	mov    %eax,%edx
  40218e:	89 f0                	mov    %esi,%eax
  402190:	eb d4                	jmp    402166 <.text+0xc6>
  402192:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  402198:	0f b6 48 01          	movzbl 0x1(%eax),%ecx
  40219c:	8d 50 01             	lea    0x1(%eax),%edx
  40219f:	3b 6c 24 1c          	cmp    0x1c(%esp),%ebp
  4021a3:	0f 84 a7 01 00 00    	je     402350 <.text+0x2b0>
  4021a9:	0f be e9             	movsbl %cl,%ebp
  4021ac:	e9 17 ff ff ff       	jmp    4020c8 <.text+0x28>
  4021b1:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  4021b8:	0f be 5d 01          	movsbl 0x1(%ebp),%ebx
  4021bc:	80 fb 5d             	cmp    $0x5d,%bl
  4021bf:	74 17                	je     4021d8 <.text+0x138>
  4021c1:	0f be f3             	movsbl %bl,%esi
  4021c4:	85 f6                	test   %esi,%esi
  4021c6:	75 20                	jne    4021e8 <.text+0x148>
  4021c8:	31 c0                	xor    %eax,%eax
  4021ca:	83 c4 3c             	add    $0x3c,%esp
  4021cd:	5b                   	pop    %ebx
  4021ce:	5e                   	pop    %esi
  4021cf:	5f                   	pop    %edi
  4021d0:	5d                   	pop    %ebp
  4021d1:	c3                   	ret    
  4021d2:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  4021d8:	89 fd                	mov    %edi,%ebp
  4021da:	ba 2d 00 00 00       	mov    $0x2d,%edx
  4021df:	e9 3e ff ff ff       	jmp    402122 <.text+0x82>
  4021e4:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  4021e8:	8d 7d 02             	lea    0x2(%ebp),%edi
  4021eb:	89 6c 24 24          	mov    %ebp,0x24(%esp)
  4021ef:	89 d5                	mov    %edx,%ebp
  4021f1:	89 7c 24 2c          	mov    %edi,0x2c(%esp)
  4021f5:	89 f7                	mov    %esi,%edi
  4021f7:	8b 74 24 20          	mov    0x20(%esp),%esi
  4021fb:	eb 10                	jmp    40220d <.text+0x16d>
  4021fd:	8d 76 00             	lea    0x0(%esi),%esi
  402200:	89 eb                	mov    %ebp,%ebx
  402202:	2b 5c 24 1c          	sub    0x1c(%esp),%ebx
  402206:	83 c5 01             	add    $0x1,%ebp
  402209:	85 db                	test   %ebx,%ebx
  40220b:	74 27                	je     402234 <.text+0x194>
  40220d:	39 fd                	cmp    %edi,%ebp
  40220f:	7d 7f                	jge    402290 <.text+0x1f0>
  402211:	85 f6                	test   %esi,%esi
  402213:	75 eb                	jne    402200 <.text+0x160>
  402215:	89 2c 24             	mov    %ebp,(%esp)
  402218:	83 c5 01             	add    $0x1,%ebp
  40221b:	e8 6c 1b 00 00       	call   403d8c <_tolower>
  402220:	89 c3                	mov    %eax,%ebx
  402222:	8b 44 24 1c          	mov    0x1c(%esp),%eax
  402226:	89 04 24             	mov    %eax,(%esp)
  402229:	e8 5e 1b 00 00       	call   403d8c <_tolower>
  40222e:	29 c3                	sub    %eax,%ebx
  402230:	85 db                	test   %ebx,%ebx
  402232:	75 d9                	jne    40220d <.text+0x16d>
  402234:	8b 54 24 24          	mov    0x24(%esp),%edx
  402238:	8b 4c 24 28          	mov    0x28(%esp),%ecx
  40223c:	8b 7c 24 2c          	mov    0x2c(%esp),%edi
  402240:	0f b6 52 02          	movzbl 0x2(%edx),%edx
  402244:	83 e1 20             	and    $0x20,%ecx
  402247:	8d 47 01             	lea    0x1(%edi),%eax
  40224a:	80 fa 5d             	cmp    $0x5d,%dl
  40224d:	0f 84 77 ff ff ff    	je     4021ca <.text+0x12a>
  402253:	80 fa 7f             	cmp    $0x7f,%dl
  402256:	74 1f                	je     402277 <.text+0x1d7>
  402258:	84 d2                	test   %dl,%dl
  40225a:	0f 84 68 ff ff ff    	je     4021c8 <.text+0x128>
  402260:	0f b6 57 01          	movzbl 0x1(%edi),%edx
  402264:	89 c7                	mov    %eax,%edi
  402266:	8d 47 01             	lea    0x1(%edi),%eax
  402269:	80 fa 5d             	cmp    $0x5d,%dl
  40226c:	0f 84 58 ff ff ff    	je     4021ca <.text+0x12a>
  402272:	80 fa 7f             	cmp    $0x7f,%dl
  402275:	75 e1                	jne    402258 <.text+0x1b8>
  402277:	0f b6 57 01          	movzbl 0x1(%edi),%edx
  40227b:	85 c9                	test   %ecx,%ecx
  40227d:	0f 85 bd 00 00 00    	jne    402340 <.text+0x2a0>
  402283:	8d 5f 02             	lea    0x2(%edi),%ebx
  402286:	89 c7                	mov    %eax,%edi
  402288:	89 d8                	mov    %ebx,%eax
  40228a:	eb cc                	jmp    402258 <.text+0x1b8>
  40228c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  402290:	89 fe                	mov    %edi,%esi
  402292:	89 ea                	mov    %ebp,%edx
  402294:	8b 7c 24 2c          	mov    0x2c(%esp),%edi
  402298:	8b 6c 24 24          	mov    0x24(%esp),%ebp
  40229c:	89 7c 24 24          	mov    %edi,0x24(%esp)
  4022a0:	89 f7                	mov    %esi,%edi
  4022a2:	89 d6                	mov    %edx,%esi
  4022a4:	89 6c 24 2c          	mov    %ebp,0x2c(%esp)
  4022a8:	8b 6c 24 20          	mov    0x20(%esp),%ebp
  4022ac:	eb 0f                	jmp    4022bd <.text+0x21d>
  4022ae:	66 90                	xchg   %ax,%ax
  4022b0:	89 f3                	mov    %esi,%ebx
  4022b2:	2b 5c 24 1c          	sub    0x1c(%esp),%ebx
  4022b6:	83 ee 01             	sub    $0x1,%esi
  4022b9:	85 db                	test   %ebx,%ebx
  4022bb:	74 2b                	je     4022e8 <.text+0x248>
  4022bd:	39 fe                	cmp    %edi,%esi
  4022bf:	0f 8e eb 00 00 00    	jle    4023b0 <.text+0x310>
  4022c5:	85 ed                	test   %ebp,%ebp
  4022c7:	75 e7                	jne    4022b0 <.text+0x210>
  4022c9:	89 34 24             	mov    %esi,(%esp)
  4022cc:	83 ee 01             	sub    $0x1,%esi
  4022cf:	e8 b8 1a 00 00       	call   403d8c <_tolower>
  4022d4:	89 c3                	mov    %eax,%ebx
  4022d6:	8b 44 24 1c          	mov    0x1c(%esp),%eax
  4022da:	89 04 24             	mov    %eax,(%esp)
  4022dd:	e8 aa 1a 00 00       	call   403d8c <_tolower>
  4022e2:	29 c3                	sub    %eax,%ebx
  4022e4:	85 db                	test   %ebx,%ebx
  4022e6:	75 d5                	jne    4022bd <.text+0x21d>
  4022e8:	8b 54 24 2c          	mov    0x2c(%esp),%edx
  4022ec:	8b 4c 24 28          	mov    0x28(%esp),%ecx
  4022f0:	8b 7c 24 24          	mov    0x24(%esp),%edi
  4022f4:	0f b6 52 02          	movzbl 0x2(%edx),%edx
  4022f8:	83 e1 20             	and    $0x20,%ecx
  4022fb:	8d 47 01             	lea    0x1(%edi),%eax
  4022fe:	80 fa 5d             	cmp    $0x5d,%dl
  402301:	0f 84 c3 fe ff ff    	je     4021ca <.text+0x12a>
  402307:	80 fa 7f             	cmp    $0x7f,%dl
  40230a:	74 1f                	je     40232b <.text+0x28b>
  40230c:	84 d2                	test   %dl,%dl
  40230e:	0f 84 b4 fe ff ff    	je     4021c8 <.text+0x128>
  402314:	0f b6 57 01          	movzbl 0x1(%edi),%edx
  402318:	89 c7                	mov    %eax,%edi
  40231a:	8d 47 01             	lea    0x1(%edi),%eax
  40231d:	80 fa 5d             	cmp    $0x5d,%dl
  402320:	0f 84 a4 fe ff ff    	je     4021ca <.text+0x12a>
  402326:	80 fa 7f             	cmp    $0x7f,%dl
  402329:	75 e1                	jne    40230c <.text+0x26c>
  40232b:	0f b6 57 01          	movzbl 0x1(%edi),%edx
  40232f:	85 c9                	test   %ecx,%ecx
  402331:	0f 85 89 00 00 00    	jne    4023c0 <.text+0x320>
  402337:	8d 5f 02             	lea    0x2(%edi),%ebx
  40233a:	89 c7                	mov    %eax,%edi
  40233c:	89 d8                	mov    %ebx,%eax
  40233e:	eb cc                	jmp    40230c <.text+0x26c>
  402340:	89 c7                	mov    %eax,%edi
  402342:	e9 00 ff ff ff       	jmp    402247 <.text+0x1a7>
  402347:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  40234e:	66 90                	xchg   %ax,%ax
  402350:	8b 5c 24 28          	mov    0x28(%esp),%ebx
  402354:	83 e3 20             	and    $0x20,%ebx
  402357:	8d 42 01             	lea    0x1(%edx),%eax
  40235a:	80 f9 5d             	cmp    $0x5d,%cl
  40235d:	0f 84 67 fe ff ff    	je     4021ca <.text+0x12a>
  402363:	80 f9 7f             	cmp    $0x7f,%cl
  402366:	74 1f                	je     402387 <.text+0x2e7>
  402368:	84 c9                	test   %cl,%cl
  40236a:	0f 84 58 fe ff ff    	je     4021c8 <.text+0x128>
  402370:	0f b6 4a 01          	movzbl 0x1(%edx),%ecx
  402374:	89 c2                	mov    %eax,%edx
  402376:	8d 42 01             	lea    0x1(%edx),%eax
  402379:	80 f9 5d             	cmp    $0x5d,%cl
  40237c:	0f 84 48 fe ff ff    	je     4021ca <.text+0x12a>
  402382:	80 f9 7f             	cmp    $0x7f,%cl
  402385:	75 e1                	jne    402368 <.text+0x2c8>
  402387:	0f b6 4a 01          	movzbl 0x1(%edx),%ecx
  40238b:	85 db                	test   %ebx,%ebx
  40238d:	75 11                	jne    4023a0 <.text+0x300>
  40238f:	8d 72 02             	lea    0x2(%edx),%esi
  402392:	89 c2                	mov    %eax,%edx
  402394:	89 f0                	mov    %esi,%eax
  402396:	eb d0                	jmp    402368 <.text+0x2c8>
  402398:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  40239f:	90                   	nop
  4023a0:	89 c2                	mov    %eax,%edx
  4023a2:	eb b3                	jmp    402357 <.text+0x2b7>
  4023a4:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  4023a8:	89 c2                	mov    %eax,%edx
  4023aa:	e9 aa fd ff ff       	jmp    402159 <.text+0xb9>
  4023af:	90                   	nop
  4023b0:	89 fe                	mov    %edi,%esi
  4023b2:	8b 7c 24 24          	mov    0x24(%esp),%edi
  4023b6:	e9 4e fd ff ff       	jmp    402109 <.text+0x69>
  4023bb:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  4023bf:	90                   	nop
  4023c0:	89 c7                	mov    %eax,%edi
  4023c2:	e9 34 ff ff ff       	jmp    4022fb <.text+0x25b>
  4023c7:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  4023ce:	66 90                	xchg   %ax,%ax
  4023d0:	55                   	push   %ebp
  4023d1:	89 c5                	mov    %eax,%ebp
  4023d3:	57                   	push   %edi
  4023d4:	56                   	push   %esi
  4023d5:	89 d6                	mov    %edx,%esi
  4023d7:	53                   	push   %ebx
  4023d8:	83 ec 2c             	sub    $0x2c,%esp
  4023db:	0f b6 3a             	movzbl (%edx),%edi
  4023de:	0f be 10             	movsbl (%eax),%edx
  4023e1:	89 fb                	mov    %edi,%ebx
  4023e3:	89 d0                	mov    %edx,%eax
  4023e5:	80 fb 2e             	cmp    $0x2e,%bl
  4023e8:	0f 84 32 01 00 00    	je     402520 <.text+0x480>
  4023ee:	8d 5d 01             	lea    0x1(%ebp),%ebx
  4023f1:	85 d2                	test   %edx,%edx
  4023f3:	0f 84 f9 00 00 00    	je     4024f2 <.text+0x452>
  4023f9:	89 cf                	mov    %ecx,%edi
  4023fb:	83 e7 20             	and    $0x20,%edi
  4023fe:	89 7c 24 14          	mov    %edi,0x14(%esp)
  402402:	89 f7                	mov    %esi,%edi
  402404:	3c 3f                	cmp    $0x3f,%al
  402406:	0f 84 f4 00 00 00    	je     402500 <.text+0x460>
  40240c:	3c 5b                	cmp    $0x5b,%al
  40240e:	0f 84 9c 00 00 00    	je     4024b0 <.text+0x410>
  402414:	3c 2a                	cmp    $0x2a,%al
  402416:	74 5b                	je     402473 <.text+0x3d3>
  402418:	f6 c1 20             	test   $0x20,%cl
  40241b:	75 09                	jne    402426 <.text+0x386>
  40241d:	83 fa 7f             	cmp    $0x7f,%edx
  402420:	0f 84 42 01 00 00    	je     402568 <.text+0x4c8>
  402426:	0f be 06             	movsbl (%esi),%eax
  402429:	84 c0                	test   %al,%al
  40242b:	74 75                	je     4024a2 <.text+0x402>
  40242d:	89 44 24 10          	mov    %eax,0x10(%esp)
  402431:	f6 c5 40             	test   $0x40,%ch
  402434:	0f 85 d6 00 00 00    	jne    402510 <.text+0x470>
  40243a:	89 14 24             	mov    %edx,(%esp)
  40243d:	89 4c 24 1c          	mov    %ecx,0x1c(%esp)
  402441:	89 54 24 18          	mov    %edx,0x18(%esp)
  402445:	e8 42 19 00 00       	call   403d8c <_tolower>
  40244a:	89 c5                	mov    %eax,%ebp
  40244c:	8b 44 24 10          	mov    0x10(%esp),%eax
  402450:	89 04 24             	mov    %eax,(%esp)
  402453:	e8 34 19 00 00       	call   403d8c <_tolower>
  402458:	8b 4c 24 1c          	mov    0x1c(%esp),%ecx
  40245c:	8b 54 24 18          	mov    0x18(%esp),%edx
  402460:	29 c5                	sub    %eax,%ebp
  402462:	85 ed                	test   %ebp,%ebp
  402464:	0f 84 9f 00 00 00    	je     402509 <.text+0x469>
  40246a:	2b 54 24 10          	sub    0x10(%esp),%edx
  40246e:	eb 32                	jmp    4024a2 <.text+0x402>
  402470:	83 c3 01             	add    $0x1,%ebx
  402473:	0f b6 03             	movzbl (%ebx),%eax
  402476:	3c 2a                	cmp    $0x2a,%al
  402478:	74 f6                	je     402470 <.text+0x3d0>
  40247a:	31 d2                	xor    %edx,%edx
  40247c:	84 c0                	test   %al,%al
  40247e:	74 22                	je     4024a2 <.text+0x402>
  402480:	89 ce                	mov    %ecx,%esi
  402482:	81 ce 00 00 01 00    	or     $0x10000,%esi
  402488:	89 f1                	mov    %esi,%ecx
  40248a:	89 fa                	mov    %edi,%edx
  40248c:	89 d8                	mov    %ebx,%eax
  40248e:	e8 3d ff ff ff       	call   4023d0 <.text+0x330>
  402493:	85 c0                	test   %eax,%eax
  402495:	74 09                	je     4024a0 <.text+0x400>
  402497:	83 c7 01             	add    $0x1,%edi
  40249a:	80 7f ff 00          	cmpb   $0x0,-0x1(%edi)
  40249e:	75 e8                	jne    402488 <.text+0x3e8>
  4024a0:	89 c2                	mov    %eax,%edx
  4024a2:	83 c4 2c             	add    $0x2c,%esp
  4024a5:	89 d0                	mov    %edx,%eax
  4024a7:	5b                   	pop    %ebx
  4024a8:	5e                   	pop    %esi
  4024a9:	5f                   	pop    %edi
  4024aa:	5d                   	pop    %ebp
  4024ab:	c3                   	ret    
  4024ac:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  4024b0:	0f be 16             	movsbl (%esi),%edx
  4024b3:	85 d2                	test   %edx,%edx
  4024b5:	0f 84 32 01 00 00    	je     4025ed <.text+0x54d>
  4024bb:	80 7d 01 21          	cmpb   $0x21,0x1(%ebp)
  4024bf:	74 7f                	je     402540 <.text+0x4a0>
  4024c1:	89 d8                	mov    %ebx,%eax
  4024c3:	89 4c 24 10          	mov    %ecx,0x10(%esp)
  4024c7:	e8 d4 fb ff ff       	call   4020a0 <.text>
  4024cc:	89 c5                	mov    %eax,%ebp
  4024ce:	85 c0                	test   %eax,%eax
  4024d0:	0f 84 03 01 00 00    	je     4025d9 <.text+0x539>
  4024d6:	0f b6 00             	movzbl (%eax),%eax
  4024d9:	8b 4c 24 10          	mov    0x10(%esp),%ecx
  4024dd:	0f be d0             	movsbl %al,%edx
  4024e0:	8d 5d 01             	lea    0x1(%ebp),%ebx
  4024e3:	83 c6 01             	add    $0x1,%esi
  4024e6:	85 d2                	test   %edx,%edx
  4024e8:	0f 85 14 ff ff ff    	jne    402402 <.text+0x362>
  4024ee:	0f b6 7f 01          	movzbl 0x1(%edi),%edi
  4024f2:	89 f8                	mov    %edi,%eax
  4024f4:	0f be d0             	movsbl %al,%edx
  4024f7:	f7 da                	neg    %edx
  4024f9:	eb a7                	jmp    4024a2 <.text+0x402>
  4024fb:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  4024ff:	90                   	nop
  402500:	80 3e 00             	cmpb   $0x0,(%esi)
  402503:	0f 84 da 00 00 00    	je     4025e3 <.text+0x543>
  402509:	0f b6 03             	movzbl (%ebx),%eax
  40250c:	89 dd                	mov    %ebx,%ebp
  40250e:	eb cd                	jmp    4024dd <.text+0x43d>
  402510:	89 d5                	mov    %edx,%ebp
  402512:	29 c5                	sub    %eax,%ebp
  402514:	e9 49 ff ff ff       	jmp    402462 <.text+0x3c2>
  402519:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  402520:	80 fa 2e             	cmp    $0x2e,%dl
  402523:	74 5b                	je     402580 <.text+0x4e0>
  402525:	f7 c1 00 00 01 00    	test   $0x10000,%ecx
  40252b:	0f 85 bd fe ff ff    	jne    4023ee <.text+0x34e>
  402531:	83 ea 2e             	sub    $0x2e,%edx
  402534:	e9 69 ff ff ff       	jmp    4024a2 <.text+0x402>
  402539:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  402540:	8d 5d 02             	lea    0x2(%ebp),%ebx
  402543:	89 4c 24 10          	mov    %ecx,0x10(%esp)
  402547:	89 d8                	mov    %ebx,%eax
  402549:	e8 52 fb ff ff       	call   4020a0 <.text>
  40254e:	8b 4c 24 10          	mov    0x10(%esp),%ecx
  402552:	89 c2                	mov    %eax,%edx
  402554:	0f b6 45 02          	movzbl 0x2(%ebp),%eax
  402558:	85 d2                	test   %edx,%edx
  40255a:	74 2c                	je     402588 <.text+0x4e8>
  40255c:	89 dd                	mov    %ebx,%ebp
  40255e:	e9 7a ff ff ff       	jmp    4024dd <.text+0x43d>
  402563:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  402567:	90                   	nop
  402568:	0f be 55 01          	movsbl 0x1(%ebp),%edx
  40256c:	85 d2                	test   %edx,%edx
  40256e:	0f 84 b2 fe ff ff    	je     402426 <.text+0x386>
  402574:	8d 5d 02             	lea    0x2(%ebp),%ebx
  402577:	e9 aa fe ff ff       	jmp    402426 <.text+0x386>
  40257c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  402580:	8d 5d 01             	lea    0x1(%ebp),%ebx
  402583:	e9 71 fe ff ff       	jmp    4023f9 <.text+0x359>
  402588:	3c 5d                	cmp    $0x5d,%al
  40258a:	75 0c                	jne    402598 <.text+0x4f8>
  40258c:	0f b6 45 03          	movzbl 0x3(%ebp),%eax
  402590:	8d 5d 03             	lea    0x3(%ebp),%ebx
  402593:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  402597:	90                   	nop
  402598:	8d 6b 01             	lea    0x1(%ebx),%ebp
  40259b:	3c 5d                	cmp    $0x5d,%al
  40259d:	74 15                	je     4025b4 <.text+0x514>
  40259f:	3c 7f                	cmp    $0x7f,%al
  4025a1:	74 1d                	je     4025c0 <.text+0x520>
  4025a3:	84 c0                	test   %al,%al
  4025a5:	74 32                	je     4025d9 <.text+0x539>
  4025a7:	0f b6 43 01          	movzbl 0x1(%ebx),%eax
  4025ab:	89 eb                	mov    %ebp,%ebx
  4025ad:	8d 6b 01             	lea    0x1(%ebx),%ebp
  4025b0:	3c 5d                	cmp    $0x5d,%al
  4025b2:	75 eb                	jne    40259f <.text+0x4ff>
  4025b4:	0f b6 43 01          	movzbl 0x1(%ebx),%eax
  4025b8:	e9 20 ff ff ff       	jmp    4024dd <.text+0x43d>
  4025bd:	8d 76 00             	lea    0x0(%esi),%esi
  4025c0:	8b 54 24 14          	mov    0x14(%esp),%edx
  4025c4:	0f b6 43 01          	movzbl 0x1(%ebx),%eax
  4025c8:	85 d2                	test   %edx,%edx
  4025ca:	75 09                	jne    4025d5 <.text+0x535>
  4025cc:	8d 53 02             	lea    0x2(%ebx),%edx
  4025cf:	89 eb                	mov    %ebp,%ebx
  4025d1:	89 d5                	mov    %edx,%ebp
  4025d3:	eb ce                	jmp    4025a3 <.text+0x503>
  4025d5:	89 eb                	mov    %ebp,%ebx
  4025d7:	eb bf                	jmp    402598 <.text+0x4f8>
  4025d9:	ba 5d 00 00 00       	mov    $0x5d,%edx
  4025de:	e9 bf fe ff ff       	jmp    4024a2 <.text+0x402>
  4025e3:	ba 3f 00 00 00       	mov    $0x3f,%edx
  4025e8:	e9 b5 fe ff ff       	jmp    4024a2 <.text+0x402>
  4025ed:	ba 5b 00 00 00       	mov    $0x5b,%edx
  4025f2:	e9 ab fe ff ff       	jmp    4024a2 <.text+0x402>
  4025f7:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  4025fe:	66 90                	xchg   %ax,%ax
  402600:	57                   	push   %edi
  402601:	8d 48 01             	lea    0x1(%eax),%ecx
  402604:	56                   	push   %esi
  402605:	53                   	push   %ebx
  402606:	89 c3                	mov    %eax,%ebx
  402608:	0f be 00             	movsbl (%eax),%eax
  40260b:	85 c0                	test   %eax,%eax
  40260d:	74 61                	je     402670 <.text+0x5d0>
  40260f:	c1 ea 05             	shr    $0x5,%edx
  402612:	31 ff                	xor    %edi,%edi
  402614:	89 d6                	mov    %edx,%esi
  402616:	83 f6 01             	xor    $0x1,%esi
  402619:	83 e6 01             	and    $0x1,%esi
  40261c:	eb 23                	jmp    402641 <.text+0x5a1>
  40261e:	66 90                	xchg   %ax,%ax
  402620:	83 f8 2a             	cmp    $0x2a,%eax
  402623:	74 6b                	je     402690 <.text+0x5f0>
  402625:	83 f8 3f             	cmp    $0x3f,%eax
  402628:	74 66                	je     402690 <.text+0x5f0>
  40262a:	83 f8 5b             	cmp    $0x5b,%eax
  40262d:	89 cb                	mov    %ecx,%ebx
  40262f:	0f 94 c0             	sete   %al
  402632:	0f b6 c0             	movzbl %al,%eax
  402635:	89 c7                	mov    %eax,%edi
  402637:	0f be 03             	movsbl (%ebx),%eax
  40263a:	83 c1 01             	add    $0x1,%ecx
  40263d:	85 c0                	test   %eax,%eax
  40263f:	74 2f                	je     402670 <.text+0x5d0>
  402641:	83 f8 7f             	cmp    $0x7f,%eax
  402644:	75 06                	jne    40264c <.text+0x5ac>
  402646:	89 f2                	mov    %esi,%edx
  402648:	84 d2                	test   %dl,%dl
  40264a:	75 2c                	jne    402678 <.text+0x5d8>
  40264c:	85 ff                	test   %edi,%edi
  40264e:	74 d0                	je     402620 <.text+0x580>
  402650:	83 ff 01             	cmp    $0x1,%edi
  402653:	7e 05                	jle    40265a <.text+0x5ba>
  402655:	83 f8 5d             	cmp    $0x5d,%eax
  402658:	74 36                	je     402690 <.text+0x5f0>
  40265a:	89 cb                	mov    %ecx,%ebx
  40265c:	83 f8 21             	cmp    $0x21,%eax
  40265f:	74 d6                	je     402637 <.text+0x597>
  402661:	89 cb                	mov    %ecx,%ebx
  402663:	83 c7 01             	add    $0x1,%edi
  402666:	83 c1 01             	add    $0x1,%ecx
  402669:	0f be 03             	movsbl (%ebx),%eax
  40266c:	85 c0                	test   %eax,%eax
  40266e:	75 d1                	jne    402641 <.text+0x5a1>
  402670:	5b                   	pop    %ebx
  402671:	5e                   	pop    %esi
  402672:	5f                   	pop    %edi
  402673:	c3                   	ret    
  402674:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  402678:	80 7b 01 00          	cmpb   $0x0,0x1(%ebx)
  40267c:	8d 4b 02             	lea    0x2(%ebx),%ecx
  40267f:	74 18                	je     402699 <.text+0x5f9>
  402681:	85 ff                	test   %edi,%edi
  402683:	74 a5                	je     40262a <.text+0x58a>
  402685:	eb da                	jmp    402661 <.text+0x5c1>
  402687:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  40268e:	66 90                	xchg   %ax,%ax
  402690:	5b                   	pop    %ebx
  402691:	b8 01 00 00 00       	mov    $0x1,%eax
  402696:	5e                   	pop    %esi
  402697:	5f                   	pop    %edi
  402698:	c3                   	ret    
  402699:	31 c0                	xor    %eax,%eax
  40269b:	eb d3                	jmp    402670 <.text+0x5d0>
  40269d:	8d 76 00             	lea    0x0(%esi),%esi
  4026a0:	57                   	push   %edi
  4026a1:	56                   	push   %esi
  4026a2:	89 c6                	mov    %eax,%esi
  4026a4:	53                   	push   %ebx
  4026a5:	89 d3                	mov    %edx,%ebx
  4026a7:	83 ec 10             	sub    $0x10,%esp
  4026aa:	8b 42 0c             	mov    0xc(%edx),%eax
  4026ad:	03 42 04             	add    0x4(%edx),%eax
  4026b0:	8d 04 85 08 00 00 00 	lea    0x8(,%eax,4),%eax
  4026b7:	89 44 24 04          	mov    %eax,0x4(%esp)
  4026bb:	8b 42 08             	mov    0x8(%edx),%eax
  4026be:	89 04 24             	mov    %eax,(%esp)
  4026c1:	e8 1a 15 00 00       	call   403be0 <___mingw_realloc>
  4026c6:	85 c0                	test   %eax,%eax
  4026c8:	74 26                	je     4026f0 <.text+0x650>
  4026ca:	8b 4b 04             	mov    0x4(%ebx),%ecx
  4026cd:	8b 53 0c             	mov    0xc(%ebx),%edx
  4026d0:	89 43 08             	mov    %eax,0x8(%ebx)
  4026d3:	8d 79 01             	lea    0x1(%ecx),%edi
  4026d6:	01 d1                	add    %edx,%ecx
  4026d8:	01 fa                	add    %edi,%edx
  4026da:	89 7b 04             	mov    %edi,0x4(%ebx)
  4026dd:	89 34 88             	mov    %esi,(%eax,%ecx,4)
  4026e0:	c7 04 90 00 00 00 00 	movl   $0x0,(%eax,%edx,4)
  4026e7:	83 c4 10             	add    $0x10,%esp
  4026ea:	31 c0                	xor    %eax,%eax
  4026ec:	5b                   	pop    %ebx
  4026ed:	5e                   	pop    %esi
  4026ee:	5f                   	pop    %edi
  4026ef:	c3                   	ret    
  4026f0:	83 c4 10             	add    $0x10,%esp
  4026f3:	b8 01 00 00 00       	mov    $0x1,%eax
  4026f8:	5b                   	pop    %ebx
  4026f9:	5e                   	pop    %esi
  4026fa:	5f                   	pop    %edi
  4026fb:	c3                   	ret    
  4026fc:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  402700:	56                   	push   %esi
  402701:	89 d6                	mov    %edx,%esi
  402703:	53                   	push   %ebx
  402704:	89 c3                	mov    %eax,%ebx
  402706:	83 ec 14             	sub    $0x14,%esp
  402709:	8b 00                	mov    (%eax),%eax
  40270b:	85 c0                	test   %eax,%eax
  40270d:	74 05                	je     402714 <.text+0x674>
  40270f:	e8 ec ff ff ff       	call   402700 <.text+0x660>
  402714:	8b 43 08             	mov    0x8(%ebx),%eax
  402717:	85 c0                	test   %eax,%eax
  402719:	74 04                	je     40271f <.text+0x67f>
  40271b:	85 f6                	test   %esi,%esi
  40271d:	75 21                	jne    402740 <.text+0x6a0>
  40271f:	8b 43 04             	mov    0x4(%ebx),%eax
  402722:	85 c0                	test   %eax,%eax
  402724:	74 07                	je     40272d <.text+0x68d>
  402726:	89 f2                	mov    %esi,%edx
  402728:	e8 d3 ff ff ff       	call   402700 <.text+0x660>
  40272d:	89 1c 24             	mov    %ebx,(%esp)
  402730:	e8 3b f9 ff ff       	call   402070 <___mingw_aligned_free>
  402735:	83 c4 14             	add    $0x14,%esp
  402738:	5b                   	pop    %ebx
  402739:	5e                   	pop    %esi
  40273a:	c3                   	ret    
  40273b:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  40273f:	90                   	nop
  402740:	89 f2                	mov    %esi,%edx
  402742:	e8 59 ff ff ff       	call   4026a0 <.text+0x600>
  402747:	eb d6                	jmp    40271f <.text+0x67f>
  402749:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  402750:	56                   	push   %esi
  402751:	89 c6                	mov    %eax,%esi
  402753:	53                   	push   %ebx
  402754:	83 ec 14             	sub    $0x14,%esp
  402757:	8b 40 0c             	mov    0xc(%eax),%eax
  40275a:	8d 58 01             	lea    0x1(%eax),%ebx
  40275d:	8d 04 9d 00 00 00 00 	lea    0x0(,%ebx,4),%eax
  402764:	89 04 24             	mov    %eax,(%esp)
  402767:	e8 68 16 00 00       	call   403dd4 <_malloc>
  40276c:	89 46 08             	mov    %eax,0x8(%esi)
  40276f:	85 c0                	test   %eax,%eax
  402771:	74 21                	je     402794 <.text+0x6f4>
  402773:	c7 46 04 00 00 00 00 	movl   $0x0,0x4(%esi)
  40277a:	85 db                	test   %ebx,%ebx
  40277c:	7e 0e                	jle    40278c <.text+0x6ec>
  40277e:	66 90                	xchg   %ax,%ax
  402780:	83 eb 01             	sub    $0x1,%ebx
  402783:	c7 04 98 00 00 00 00 	movl   $0x0,(%eax,%ebx,4)
  40278a:	75 f4                	jne    402780 <.text+0x6e0>
  40278c:	31 c0                	xor    %eax,%eax
  40278e:	83 c4 14             	add    $0x14,%esp
  402791:	5b                   	pop    %ebx
  402792:	5e                   	pop    %esi
  402793:	c3                   	ret    
  402794:	b8 03 00 00 00       	mov    $0x3,%eax
  402799:	eb f3                	jmp    40278e <.text+0x6ee>
  40279b:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  40279f:	90                   	nop
  4027a0:	55                   	push   %ebp
  4027a1:	89 e5                	mov    %esp,%ebp
  4027a3:	57                   	push   %edi
  4027a4:	56                   	push   %esi
  4027a5:	53                   	push   %ebx
  4027a6:	83 ec 6c             	sub    $0x6c,%esp
  4027a9:	89 45 c4             	mov    %eax,-0x3c(%ebp)
  4027ac:	89 55 d0             	mov    %edx,-0x30(%ebp)
  4027af:	89 4d c8             	mov    %ecx,-0x38(%ebp)
  4027b2:	80 e6 04             	and    $0x4,%dh
  4027b5:	0f 85 3d 01 00 00    	jne    4028f8 <.text+0x858>
  4027bb:	8b 7d c4             	mov    -0x3c(%ebp),%edi
  4027be:	89 65 bc             	mov    %esp,-0x44(%ebp)
  4027c1:	89 3c 24             	mov    %edi,(%esp)
  4027c4:	e8 cb 15 00 00       	call   403d94 <_strlen>
  4027c9:	8d 50 01             	lea    0x1(%eax),%edx
  4027cc:	83 c0 10             	add    $0x10,%eax
  4027cf:	c1 e8 04             	shr    $0x4,%eax
  4027d2:	c1 e0 04             	shl    $0x4,%eax
  4027d5:	e8 66 15 00 00       	call   403d40 <___chkstk_ms>
  4027da:	29 c4                	sub    %eax,%esp
  4027dc:	8d 44 24 0c          	lea    0xc(%esp),%eax
  4027e0:	89 54 24 08          	mov    %edx,0x8(%esp)
  4027e4:	89 7c 24 04          	mov    %edi,0x4(%esp)
  4027e8:	89 04 24             	mov    %eax,(%esp)
  4027eb:	e8 d4 15 00 00       	call   403dc4 <_memcpy>
  4027f0:	89 04 24             	mov    %eax,(%esp)
  4027f3:	e8 a8 09 00 00       	call   4031a0 <___mingw_dirname>
  4027f8:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%ebp)
  4027ff:	89 45 c0             	mov    %eax,-0x40(%ebp)
  402802:	89 c7                	mov    %eax,%edi
  402804:	8d 45 d8             	lea    -0x28(%ebp),%eax
  402807:	e8 44 ff ff ff       	call   402750 <.text+0x6b0>
  40280c:	89 45 d4             	mov    %eax,-0x2c(%ebp)
  40280f:	85 c0                	test   %eax,%eax
  402811:	0f 85 81 03 00 00    	jne    402b98 <.text+0xaf8>
  402817:	85 ff                	test   %edi,%edi
  402819:	74 12                	je     40282d <.text+0x78d>
  40281b:	8b 55 d0             	mov    -0x30(%ebp),%edx
  40281e:	89 f8                	mov    %edi,%eax
  402820:	e8 db fd ff ff       	call   402600 <.text+0x560>
  402825:	85 c0                	test   %eax,%eax
  402827:	0f 85 f9 05 00 00    	jne    402e26 <.text+0xd86>
  40282d:	8b 75 c0             	mov    -0x40(%ebp),%esi
  402830:	89 e3                	mov    %esp,%ebx
  402832:	89 34 24             	mov    %esi,(%esp)
  402835:	e8 5a 15 00 00       	call   403d94 <_strlen>
  40283a:	83 c0 10             	add    $0x10,%eax
  40283d:	c1 e8 04             	shr    $0x4,%eax
  402840:	c1 e0 04             	shl    $0x4,%eax
  402843:	e8 f8 14 00 00       	call   403d40 <___chkstk_ms>
  402848:	29 c4                	sub    %eax,%esp
  40284a:	89 f2                	mov    %esi,%edx
  40284c:	8d 7c 24 0c          	lea    0xc(%esp),%edi
  402850:	89 f9                	mov    %edi,%ecx
  402852:	eb 10                	jmp    402864 <.text+0x7c4>
  402854:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  402858:	83 c1 01             	add    $0x1,%ecx
  40285b:	89 f2                	mov    %esi,%edx
  40285d:	88 41 ff             	mov    %al,-0x1(%ecx)
  402860:	84 c0                	test   %al,%al
  402862:	74 1b                	je     40287f <.text+0x7df>
  402864:	0f b6 02             	movzbl (%edx),%eax
  402867:	8d 72 01             	lea    0x1(%edx),%esi
  40286a:	3c 7f                	cmp    $0x7f,%al
  40286c:	75 ea                	jne    402858 <.text+0x7b8>
  40286e:	0f b6 42 01          	movzbl 0x1(%edx),%eax
  402872:	83 c1 01             	add    $0x1,%ecx
  402875:	83 c2 02             	add    $0x2,%edx
  402878:	88 41 ff             	mov    %al,-0x1(%ecx)
  40287b:	84 c0                	test   %al,%al
  40287d:	75 e5                	jne    402864 <.text+0x7c4>
  40287f:	89 3c 24             	mov    %edi,(%esp)
  402882:	e8 ed 14 00 00       	call   403d74 <_strdup>
  402887:	c7 45 d4 01 00 00 00 	movl   $0x1,-0x2c(%ebp)
  40288e:	89 dc                	mov    %ebx,%esp
  402890:	85 c0                	test   %eax,%eax
  402892:	0f 84 00 03 00 00    	je     402b98 <.text+0xaf8>
  402898:	8d 55 d8             	lea    -0x28(%ebp),%edx
  40289b:	e8 00 fe ff ff       	call   4026a0 <.text+0x600>
  4028a0:	89 45 d4             	mov    %eax,-0x2c(%ebp)
  4028a3:	8b 4d d4             	mov    -0x2c(%ebp),%ecx
  4028a6:	85 c9                	test   %ecx,%ecx
  4028a8:	0f 85 ea 02 00 00    	jne    402b98 <.text+0xaf8>
  4028ae:	8b 5d c4             	mov    -0x3c(%ebp),%ebx
  4028b1:	0f b6 43 01          	movzbl 0x1(%ebx),%eax
  4028b5:	3c 2f                	cmp    $0x2f,%al
  4028b7:	0f 84 33 03 00 00    	je     402bf0 <.text+0xb50>
  4028bd:	3c 5c                	cmp    $0x5c,%al
  4028bf:	0f 84 2b 03 00 00    	je     402bf0 <.text+0xb50>
  4028c5:	8b 45 c0             	mov    -0x40(%ebp),%eax
  4028c8:	80 38 2e             	cmpb   $0x2e,(%eax)
  4028cb:	0f 85 1f 03 00 00    	jne    402bf0 <.text+0xb50>
  4028d1:	80 78 01 00          	cmpb   $0x0,0x1(%eax)
  4028d5:	0f 85 15 03 00 00    	jne    402bf0 <.text+0xb50>
  4028db:	f6 45 d0 10          	testb  $0x10,-0x30(%ebp)
  4028df:	0f 85 af 06 00 00    	jne    402f94 <.text+0xef4>
  4028e5:	c6 45 9f 5c          	movb   $0x5c,-0x61(%ebp)
  4028e9:	c7 45 c0 00 00 00 00 	movl   $0x0,-0x40(%ebp)
  4028f0:	e9 4e 03 00 00       	jmp    402c43 <.text+0xba3>
  4028f5:	8d 76 00             	lea    0x0(%esi),%esi
  4028f8:	89 65 b8             	mov    %esp,-0x48(%ebp)
  4028fb:	89 c6                	mov    %eax,%esi
  4028fd:	89 04 24             	mov    %eax,(%esp)
  402900:	e8 8f 14 00 00       	call   403d94 <_strlen>
  402905:	83 c0 10             	add    $0x10,%eax
  402908:	c1 e8 04             	shr    $0x4,%eax
  40290b:	c1 e0 04             	shl    $0x4,%eax
  40290e:	e8 2d 14 00 00       	call   403d40 <___chkstk_ms>
  402913:	0f b6 1e             	movzbl (%esi),%ebx
  402916:	29 c4                	sub    %eax,%esp
  402918:	8d 7c 24 0c          	lea    0xc(%esp),%edi
  40291c:	89 7d bc             	mov    %edi,-0x44(%ebp)
  40291f:	8d 4e 01             	lea    0x1(%esi),%ecx
  402922:	80 fb 7f             	cmp    $0x7f,%bl
  402925:	74 22                	je     402949 <.text+0x8a9>
  402927:	80 fb 7b             	cmp    $0x7b,%bl
  40292a:	74 44                	je     402970 <.text+0x8d0>
  40292c:	88 1f                	mov    %bl,(%edi)
  40292e:	8d 47 01             	lea    0x1(%edi),%eax
  402931:	84 db                	test   %bl,%bl
  402933:	0f 84 99 02 00 00    	je     402bd2 <.text+0xb32>
  402939:	0f b6 5e 01          	movzbl 0x1(%esi),%ebx
  40293d:	89 ce                	mov    %ecx,%esi
  40293f:	89 c7                	mov    %eax,%edi
  402941:	8d 4e 01             	lea    0x1(%esi),%ecx
  402944:	80 fb 7f             	cmp    $0x7f,%bl
  402947:	75 de                	jne    402927 <.text+0x887>
  402949:	0f b6 5e 01          	movzbl 0x1(%esi),%ebx
  40294d:	c6 07 7f             	movb   $0x7f,(%edi)
  402950:	84 db                	test   %bl,%bl
  402952:	75 0c                	jne    402960 <.text+0x8c0>
  402954:	8d 46 02             	lea    0x2(%esi),%eax
  402957:	83 c7 01             	add    $0x1,%edi
  40295a:	89 ce                	mov    %ecx,%esi
  40295c:	89 c1                	mov    %eax,%ecx
  40295e:	eb cc                	jmp    40292c <.text+0x88c>
  402960:	88 5f 01             	mov    %bl,0x1(%edi)
  402963:	83 c6 02             	add    $0x2,%esi
  402966:	0f b6 1e             	movzbl (%esi),%ebx
  402969:	83 c7 02             	add    $0x2,%edi
  40296c:	eb b1                	jmp    40291f <.text+0x87f>
  40296e:	66 90                	xchg   %ax,%ax
  402970:	0f b6 5e 01          	movzbl 0x1(%esi),%ebx
  402974:	89 f2                	mov    %esi,%edx
  402976:	89 75 c0             	mov    %esi,-0x40(%ebp)
  402979:	89 4d d4             	mov    %ecx,-0x2c(%ebp)
  40297c:	8d 72 01             	lea    0x1(%edx),%esi
  40297f:	b9 01 00 00 00       	mov    $0x1,%ecx
  402984:	89 d8                	mov    %ebx,%eax
  402986:	c7 45 cc 2c 00 00 00 	movl   $0x2c,-0x34(%ebp)
  40298d:	3c 7b                	cmp    $0x7b,%al
  40298f:	74 2b                	je     4029bc <.text+0x91c>
  402991:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  402998:	7f 36                	jg     4029d0 <.text+0x930>
  40299a:	84 c0                	test   %al,%al
  40299c:	0f 84 1e 01 00 00    	je     402ac0 <.text+0xa20>
  4029a2:	3c 2c                	cmp    $0x2c,%al
  4029a4:	75 09                	jne    4029af <.text+0x90f>
  4029a6:	83 f9 01             	cmp    $0x1,%ecx
  4029a9:	0f 84 11 02 00 00    	je     402bc0 <.text+0xb20>
  4029af:	0f b6 42 02          	movzbl 0x2(%edx),%eax
  4029b3:	89 f2                	mov    %esi,%edx
  4029b5:	8d 72 01             	lea    0x1(%edx),%esi
  4029b8:	3c 7b                	cmp    $0x7b,%al
  4029ba:	75 dc                	jne    402998 <.text+0x8f8>
  4029bc:	0f b6 42 02          	movzbl 0x2(%edx),%eax
  4029c0:	83 c1 01             	add    $0x1,%ecx
  4029c3:	89 f2                	mov    %esi,%edx
  4029c5:	eb ee                	jmp    4029b5 <.text+0x915>
  4029c7:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  4029ce:	66 90                	xchg   %ax,%ax
  4029d0:	3c 7d                	cmp    $0x7d,%al
  4029d2:	0f 85 18 01 00 00    	jne    402af0 <.text+0xa50>
  4029d8:	83 e9 01             	sub    $0x1,%ecx
  4029db:	75 d2                	jne    4029af <.text+0x90f>
  4029dd:	83 7d cc 7b          	cmpl   $0x7b,-0x34(%ebp)
  4029e1:	8b 75 c0             	mov    -0x40(%ebp),%esi
  4029e4:	8b 4d d4             	mov    -0x2c(%ebp),%ecx
  4029e7:	0f 85 d6 00 00 00    	jne    402ac3 <.text+0xa23>
  4029ed:	89 7d d4             	mov    %edi,-0x2c(%ebp)
  4029f0:	8b 7d d0             	mov    -0x30(%ebp),%edi
  4029f3:	8b 45 d4             	mov    -0x2c(%ebp),%eax
  4029f6:	ba 01 00 00 00       	mov    $0x1,%edx
  4029fb:	80 fb 7f             	cmp    $0x7f,%bl
  4029fe:	0f 84 98 00 00 00    	je     402a9c <.text+0x9fc>
  402a04:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  402a08:	83 c6 01             	add    $0x1,%esi
  402a0b:	89 c1                	mov    %eax,%ecx
  402a0d:	80 fb 7d             	cmp    $0x7d,%bl
  402a10:	74 6e                	je     402a80 <.text+0x9e0>
  402a12:	80 fb 2c             	cmp    $0x2c,%bl
  402a15:	0f 85 b5 00 00 00    	jne    402ad0 <.text+0xa30>
  402a1b:	83 fa 01             	cmp    $0x1,%edx
  402a1e:	0f 85 ac 00 00 00    	jne    402ad0 <.text+0xa30>
  402a24:	89 f2                	mov    %esi,%edx
  402a26:	bb 01 00 00 00       	mov    $0x1,%ebx
  402a2b:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  402a2f:	90                   	nop
  402a30:	8d 42 01             	lea    0x1(%edx),%eax
  402a33:	0f b6 52 01          	movzbl 0x1(%edx),%edx
  402a37:	80 fa 7f             	cmp    $0x7f,%dl
  402a3a:	74 1c                	je     402a58 <.text+0x9b8>
  402a3c:	e9 ef 00 00 00       	jmp    402b30 <.text+0xa90>
  402a41:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  402a48:	0f b6 50 02          	movzbl 0x2(%eax),%edx
  402a4c:	83 c0 02             	add    $0x2,%eax
  402a4f:	80 fa 7f             	cmp    $0x7f,%dl
  402a52:	0f 85 d8 00 00 00    	jne    402b30 <.text+0xa90>
  402a58:	80 78 01 00          	cmpb   $0x0,0x1(%eax)
  402a5c:	75 ea                	jne    402a48 <.text+0x9a8>
  402a5e:	c6 01 00             	movb   $0x0,(%ecx)
  402a61:	c7 45 d4 01 00 00 00 	movl   $0x1,-0x2c(%ebp)
  402a68:	8b 65 b8             	mov    -0x48(%ebp),%esp
  402a6b:	8b 45 d4             	mov    -0x2c(%ebp),%eax
  402a6e:	8d 65 f4             	lea    -0xc(%ebp),%esp
  402a71:	5b                   	pop    %ebx
  402a72:	5e                   	pop    %esi
  402a73:	5f                   	pop    %edi
  402a74:	5d                   	pop    %ebp
  402a75:	c3                   	ret    
  402a76:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  402a7d:	8d 76 00             	lea    0x0(%esi),%esi
  402a80:	83 ea 01             	sub    $0x1,%edx
  402a83:	0f 84 c7 00 00 00    	je     402b50 <.text+0xab0>
  402a89:	c6 01 7d             	movb   $0x7d,(%ecx)
  402a8c:	8d 41 01             	lea    0x1(%ecx),%eax
  402a8f:	0f b6 5e 01          	movzbl 0x1(%esi),%ebx
  402a93:	80 fb 7f             	cmp    $0x7f,%bl
  402a96:	0f 85 6c ff ff ff    	jne    402a08 <.text+0x968>
  402a9c:	0f b6 5e 02          	movzbl 0x2(%esi),%ebx
  402aa0:	c6 00 7f             	movb   $0x7f,(%eax)
  402aa3:	8d 48 02             	lea    0x2(%eax),%ecx
  402aa6:	88 58 01             	mov    %bl,0x1(%eax)
  402aa9:	84 db                	test   %bl,%bl
  402aab:	74 6b                	je     402b18 <.text+0xa78>
  402aad:	0f b6 5e 03          	movzbl 0x3(%esi),%ebx
  402ab1:	83 c6 03             	add    $0x3,%esi
  402ab4:	e9 54 ff ff ff       	jmp    402a0d <.text+0x96d>
  402ab9:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  402ac0:	8b 4d d4             	mov    -0x2c(%ebp),%ecx
  402ac3:	c6 07 7b             	movb   $0x7b,(%edi)
  402ac6:	89 ce                	mov    %ecx,%esi
  402ac8:	83 c7 01             	add    $0x1,%edi
  402acb:	e9 4f fe ff ff       	jmp    40291f <.text+0x87f>
  402ad0:	8d 41 01             	lea    0x1(%ecx),%eax
  402ad3:	80 fb 7b             	cmp    $0x7b,%bl
  402ad6:	75 08                	jne    402ae0 <.text+0xa40>
  402ad8:	c6 01 7b             	movb   $0x7b,(%ecx)
  402adb:	83 c2 01             	add    $0x1,%edx
  402ade:	eb af                	jmp    402a8f <.text+0x9ef>
  402ae0:	88 19                	mov    %bl,(%ecx)
  402ae2:	84 db                	test   %bl,%bl
  402ae4:	75 a9                	jne    402a8f <.text+0x9ef>
  402ae6:	eb 34                	jmp    402b1c <.text+0xa7c>
  402ae8:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  402aef:	90                   	nop
  402af0:	3c 7f                	cmp    $0x7f,%al
  402af2:	0f 85 b7 fe ff ff    	jne    4029af <.text+0x90f>
  402af8:	0f b6 42 02          	movzbl 0x2(%edx),%eax
  402afc:	84 c0                	test   %al,%al
  402afe:	0f 84 af fe ff ff    	je     4029b3 <.text+0x913>
  402b04:	8d 72 02             	lea    0x2(%edx),%esi
  402b07:	0f b6 42 03          	movzbl 0x3(%edx),%eax
  402b0b:	89 f2                	mov    %esi,%edx
  402b0d:	e9 a3 fe ff ff       	jmp    4029b5 <.text+0x915>
  402b12:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  402b18:	c6 40 02 00          	movb   $0x0,0x2(%eax)
  402b1c:	c7 45 d4 01 00 00 00 	movl   $0x1,-0x2c(%ebp)
  402b23:	e9 40 ff ff ff       	jmp    402a68 <.text+0x9c8>
  402b28:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  402b2f:	90                   	nop
  402b30:	80 fa 7b             	cmp    $0x7b,%dl
  402b33:	74 7b                	je     402bb0 <.text+0xb10>
  402b35:	80 fa 7d             	cmp    $0x7d,%dl
  402b38:	0f 84 a2 00 00 00    	je     402be0 <.text+0xb40>
  402b3e:	84 d2                	test   %dl,%dl
  402b40:	0f 84 18 ff ff ff    	je     402a5e <.text+0x9be>
  402b46:	89 c2                	mov    %eax,%edx
  402b48:	e9 e3 fe ff ff       	jmp    402a30 <.text+0x990>
  402b4d:	8d 76 00             	lea    0x0(%esi),%esi
  402b50:	89 f0                	mov    %esi,%eax
  402b52:	83 c0 01             	add    $0x1,%eax
  402b55:	8d 76 00             	lea    0x0(%esi),%esi
  402b58:	0f b6 10             	movzbl (%eax),%edx
  402b5b:	83 c1 01             	add    $0x1,%ecx
  402b5e:	83 c0 01             	add    $0x1,%eax
  402b61:	88 51 ff             	mov    %dl,-0x1(%ecx)
  402b64:	84 d2                	test   %dl,%dl
  402b66:	75 f0                	jne    402b58 <.text+0xab8>
  402b68:	8b 45 08             	mov    0x8(%ebp),%eax
  402b6b:	89 fa                	mov    %edi,%edx
  402b6d:	83 cf 01             	or     $0x1,%edi
  402b70:	89 04 24             	mov    %eax,(%esp)
  402b73:	8b 4d c8             	mov    -0x38(%ebp),%ecx
  402b76:	8b 45 bc             	mov    -0x44(%ebp),%eax
  402b79:	e8 22 fc ff ff       	call   4027a0 <.text+0x700>
  402b7e:	83 f8 01             	cmp    $0x1,%eax
  402b81:	74 99                	je     402b1c <.text+0xa7c>
  402b83:	80 3e 2c             	cmpb   $0x2c,(%esi)
  402b86:	0f 85 92 02 00 00    	jne    402e1e <.text+0xd7e>
  402b8c:	0f b6 5e 01          	movzbl 0x1(%esi),%ebx
  402b90:	e9 5e fe ff ff       	jmp    4029f3 <.text+0x953>
  402b95:	8d 76 00             	lea    0x0(%esi),%esi
  402b98:	8b 45 d4             	mov    -0x2c(%ebp),%eax
  402b9b:	8b 65 bc             	mov    -0x44(%ebp),%esp
  402b9e:	8d 65 f4             	lea    -0xc(%ebp),%esp
  402ba1:	5b                   	pop    %ebx
  402ba2:	5e                   	pop    %esi
  402ba3:	5f                   	pop    %edi
  402ba4:	5d                   	pop    %ebp
  402ba5:	c3                   	ret    
  402ba6:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  402bad:	8d 76 00             	lea    0x0(%esi),%esi
  402bb0:	83 c3 01             	add    $0x1,%ebx
  402bb3:	89 c2                	mov    %eax,%edx
  402bb5:	e9 76 fe ff ff       	jmp    402a30 <.text+0x990>
  402bba:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  402bc0:	0f b6 42 02          	movzbl 0x2(%edx),%eax
  402bc4:	c7 45 cc 7b 00 00 00 	movl   $0x7b,-0x34(%ebp)
  402bcb:	89 f2                	mov    %esi,%edx
  402bcd:	e9 e3 fd ff ff       	jmp    4029b5 <.text+0x915>
  402bd2:	8b 65 b8             	mov    -0x48(%ebp),%esp
  402bd5:	e9 e1 fb ff ff       	jmp    4027bb <.text+0x71b>
  402bda:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  402be0:	83 eb 01             	sub    $0x1,%ebx
  402be3:	0f 84 69 ff ff ff    	je     402b52 <.text+0xab2>
  402be9:	89 c2                	mov    %eax,%edx
  402beb:	e9 40 fe ff ff       	jmp    402a30 <.text+0x990>
  402bf0:	8b 45 c0             	mov    -0x40(%ebp),%eax
  402bf3:	89 04 24             	mov    %eax,(%esp)
  402bf6:	e8 99 11 00 00       	call   403d94 <_strlen>
  402bfb:	8b 7d c4             	mov    -0x3c(%ebp),%edi
  402bfe:	8b 55 c4             	mov    -0x3c(%ebp),%edx
  402c01:	8d 1c 07             	lea    (%edi,%eax,1),%ebx
  402c04:	0f b6 03             	movzbl (%ebx),%eax
  402c07:	39 df                	cmp    %ebx,%edi
  402c09:	73 17                	jae    402c22 <.text+0xb82>
  402c0b:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  402c0f:	90                   	nop
  402c10:	3c 2f                	cmp    $0x2f,%al
  402c12:	74 1c                	je     402c30 <.text+0xb90>
  402c14:	3c 5c                	cmp    $0x5c,%al
  402c16:	74 0a                	je     402c22 <.text+0xb82>
  402c18:	83 eb 01             	sub    $0x1,%ebx
  402c1b:	0f b6 03             	movzbl (%ebx),%eax
  402c1e:	39 da                	cmp    %ebx,%edx
  402c20:	75 ee                	jne    402c10 <.text+0xb70>
  402c22:	3c 2f                	cmp    $0x2f,%al
  402c24:	74 0a                	je     402c30 <.text+0xb90>
  402c26:	3c 5c                	cmp    $0x5c,%al
  402c28:	74 06                	je     402c30 <.text+0xb90>
  402c2a:	c6 45 9f 5c          	movb   $0x5c,-0x61(%ebp)
  402c2e:	eb 13                	jmp    402c43 <.text+0xba3>
  402c30:	83 c3 01             	add    $0x1,%ebx
  402c33:	89 c2                	mov    %eax,%edx
  402c35:	0f b6 03             	movzbl (%ebx),%eax
  402c38:	3c 2f                	cmp    $0x2f,%al
  402c3a:	74 f4                	je     402c30 <.text+0xb90>
  402c3c:	3c 5c                	cmp    $0x5c,%al
  402c3e:	74 f0                	je     402c30 <.text+0xb90>
  402c40:	88 55 9f             	mov    %dl,-0x61(%ebp)
  402c43:	8b 7d e0             	mov    -0x20(%ebp),%edi
  402c46:	c7 45 d4 02 00 00 00 	movl   $0x2,-0x2c(%ebp)
  402c4d:	8b 07                	mov    (%edi),%eax
  402c4f:	85 c0                	test   %eax,%eax
  402c51:	0f 84 36 02 00 00    	je     402e8d <.text+0xded>
  402c57:	8b 4d d0             	mov    -0x30(%ebp),%ecx
  402c5a:	89 5d b8             	mov    %ebx,-0x48(%ebp)
  402c5d:	89 fb                	mov    %edi,%ebx
  402c5f:	81 e1 00 80 00 00    	and    $0x8000,%ecx
  402c65:	89 4d c4             	mov    %ecx,-0x3c(%ebp)
  402c68:	eb 4c                	jmp    402cb6 <.text+0xc16>
  402c6a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  402c70:	f6 45 d0 04          	testb  $0x4,-0x30(%ebp)
  402c74:	75 22                	jne    402c98 <.text+0xbf8>
  402c76:	8b 7d c8             	mov    -0x38(%ebp),%edi
  402c79:	85 ff                	test   %edi,%edi
  402c7b:	74 22                	je     402c9f <.text+0xbff>
  402c7d:	e8 9a 11 00 00       	call   403e1c <__errno>
  402c82:	8b 00                	mov    (%eax),%eax
  402c84:	89 44 24 04          	mov    %eax,0x4(%esp)
  402c88:	8b 03                	mov    (%ebx),%eax
  402c8a:	89 04 24             	mov    %eax,(%esp)
  402c8d:	ff d7                	call   *%edi
  402c8f:	85 c0                	test   %eax,%eax
  402c91:	74 0c                	je     402c9f <.text+0xbff>
  402c93:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  402c97:	90                   	nop
  402c98:	c7 45 d4 01 00 00 00 	movl   $0x1,-0x2c(%ebp)
  402c9f:	8b 03                	mov    (%ebx),%eax
  402ca1:	83 c3 04             	add    $0x4,%ebx
  402ca4:	89 04 24             	mov    %eax,(%esp)
  402ca7:	e8 c4 f3 ff ff       	call   402070 <___mingw_aligned_free>
  402cac:	8b 03                	mov    (%ebx),%eax
  402cae:	85 c0                	test   %eax,%eax
  402cb0:	0f 84 e7 01 00 00    	je     402e9d <.text+0xdfd>
  402cb6:	83 7d d4 01          	cmpl   $0x1,-0x2c(%ebp)
  402cba:	74 dc                	je     402c98 <.text+0xbf8>
  402cbc:	89 04 24             	mov    %eax,(%esp)
  402cbf:	e8 ac 0a 00 00       	call   403770 <___mingw_opendir>
  402cc4:	89 45 cc             	mov    %eax,-0x34(%ebp)
  402cc7:	85 c0                	test   %eax,%eax
  402cc9:	74 a5                	je     402c70 <.text+0xbd0>
  402ccb:	8b 45 c0             	mov    -0x40(%ebp),%eax
  402cce:	c7 45 b4 00 00 00 00 	movl   $0x0,-0x4c(%ebp)
  402cd5:	85 c0                	test   %eax,%eax
  402cd7:	74 0d                	je     402ce6 <.text+0xc46>
  402cd9:	8b 03                	mov    (%ebx),%eax
  402cdb:	89 04 24             	mov    %eax,(%esp)
  402cde:	e8 b1 10 00 00       	call   403d94 <_strlen>
  402ce3:	89 45 b4             	mov    %eax,-0x4c(%ebp)
  402ce6:	8b 45 b4             	mov    -0x4c(%ebp),%eax
  402ce9:	c7 45 b0 00 00 00 00 	movl   $0x0,-0x50(%ebp)
  402cf0:	83 c0 02             	add    $0x2,%eax
  402cf3:	89 45 a0             	mov    %eax,-0x60(%ebp)
  402cf6:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  402cfd:	8d 76 00             	lea    0x0(%esi),%esi
  402d00:	8b 45 cc             	mov    -0x34(%ebp),%eax
  402d03:	89 04 24             	mov    %eax,(%esp)
  402d06:	e8 65 0c 00 00       	call   403970 <___mingw_readdir>
  402d0b:	89 c6                	mov    %eax,%esi
  402d0d:	85 c0                	test   %eax,%eax
  402d0f:	0f 84 30 01 00 00    	je     402e45 <.text+0xda5>
  402d15:	8b 7d c4             	mov    -0x3c(%ebp),%edi
  402d18:	85 ff                	test   %edi,%edi
  402d1a:	74 06                	je     402d22 <.text+0xc82>
  402d1c:	83 7e 08 10          	cmpl   $0x10,0x8(%esi)
  402d20:	75 de                	jne    402d00 <.text+0xc60>
  402d22:	8d 7e 0c             	lea    0xc(%esi),%edi
  402d25:	8b 4d d0             	mov    -0x30(%ebp),%ecx
  402d28:	8b 45 b8             	mov    -0x48(%ebp),%eax
  402d2b:	89 fa                	mov    %edi,%edx
  402d2d:	e8 9e f6 ff ff       	call   4023d0 <.text+0x330>
  402d32:	85 c0                	test   %eax,%eax
  402d34:	75 ca                	jne    402d00 <.text+0xc60>
  402d36:	0f b7 4e 06          	movzwl 0x6(%esi),%ecx
  402d3a:	8b 45 a0             	mov    -0x60(%ebp),%eax
  402d3d:	89 65 ac             	mov    %esp,-0x54(%ebp)
  402d40:	8d 44 01 0f          	lea    0xf(%ecx,%eax,1),%eax
  402d44:	c1 e8 04             	shr    $0x4,%eax
  402d47:	c1 e0 04             	shl    $0x4,%eax
  402d4a:	e8 f1 0f 00 00       	call   403d40 <___chkstk_ms>
  402d4f:	8b 75 b4             	mov    -0x4c(%ebp),%esi
  402d52:	29 c4                	sub    %eax,%esp
  402d54:	8d 54 24 0c          	lea    0xc(%esp),%edx
  402d58:	89 55 a8             	mov    %edx,-0x58(%ebp)
  402d5b:	89 d0                	mov    %edx,%eax
  402d5d:	85 f6                	test   %esi,%esi
  402d5f:	0f 85 3f 01 00 00    	jne    402ea4 <.text+0xe04>
  402d65:	83 c1 01             	add    $0x1,%ecx
  402d68:	89 55 a4             	mov    %edx,-0x5c(%ebp)
  402d6b:	89 4c 24 08          	mov    %ecx,0x8(%esp)
  402d6f:	89 7c 24 04          	mov    %edi,0x4(%esp)
  402d73:	89 e7                	mov    %esp,%edi
  402d75:	89 04 24             	mov    %eax,(%esp)
  402d78:	e8 47 10 00 00       	call   403dc4 <_memcpy>
  402d7d:	8b 55 a4             	mov    -0x5c(%ebp),%edx
  402d80:	89 14 24             	mov    %edx,(%esp)
  402d83:	e8 0c 10 00 00       	call   403d94 <_strlen>
  402d88:	83 c0 10             	add    $0x10,%eax
  402d8b:	c1 e8 04             	shr    $0x4,%eax
  402d8e:	c1 e0 04             	shl    $0x4,%eax
  402d91:	e8 aa 0f 00 00       	call   403d40 <___chkstk_ms>
  402d96:	8b 75 a8             	mov    -0x58(%ebp),%esi
  402d99:	29 c4                	sub    %eax,%esp
  402d9b:	8d 44 24 0c          	lea    0xc(%esp),%eax
  402d9f:	89 45 a4             	mov    %eax,-0x5c(%ebp)
  402da2:	89 c2                	mov    %eax,%edx
  402da4:	eb 16                	jmp    402dbc <.text+0xd1c>
  402da6:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  402dad:	8d 76 00             	lea    0x0(%esi),%esi
  402db0:	83 c2 01             	add    $0x1,%edx
  402db3:	89 ce                	mov    %ecx,%esi
  402db5:	88 42 ff             	mov    %al,-0x1(%edx)
  402db8:	84 c0                	test   %al,%al
  402dba:	74 1b                	je     402dd7 <.text+0xd37>
  402dbc:	0f b6 06             	movzbl (%esi),%eax
  402dbf:	8d 4e 01             	lea    0x1(%esi),%ecx
  402dc2:	3c 7f                	cmp    $0x7f,%al
  402dc4:	75 ea                	jne    402db0 <.text+0xd10>
  402dc6:	0f b6 46 01          	movzbl 0x1(%esi),%eax
  402dca:	83 c2 01             	add    $0x1,%edx
  402dcd:	83 c6 02             	add    $0x2,%esi
  402dd0:	88 42 ff             	mov    %al,-0x1(%edx)
  402dd3:	84 c0                	test   %al,%al
  402dd5:	75 e5                	jne    402dbc <.text+0xd1c>
  402dd7:	8b 45 a4             	mov    -0x5c(%ebp),%eax
  402dda:	89 04 24             	mov    %eax,(%esp)
  402ddd:	e8 92 0f 00 00       	call   403d74 <_strdup>
  402de2:	89 fc                	mov    %edi,%esp
  402de4:	89 c6                	mov    %eax,%esi
  402de6:	85 c0                	test   %eax,%eax
  402de8:	0f 84 38 02 00 00    	je     403026 <.text+0xf86>
  402dee:	8b 7d d4             	mov    -0x2c(%ebp),%edi
  402df1:	31 c0                	xor    %eax,%eax
  402df3:	83 ff 02             	cmp    $0x2,%edi
  402df6:	0f 94 c0             	sete   %al
  402df9:	83 e8 01             	sub    $0x1,%eax
  402dfc:	21 c7                	and    %eax,%edi
  402dfe:	89 7d d4             	mov    %edi,-0x2c(%ebp)
  402e01:	f6 45 d0 40          	testb  $0x40,-0x30(%ebp)
  402e05:	0f 84 e2 00 00 00    	je     402eed <.text+0xe4d>
  402e0b:	8b 55 08             	mov    0x8(%ebp),%edx
  402e0e:	85 d2                	test   %edx,%edx
  402e10:	0f 85 5e 01 00 00    	jne    402f74 <.text+0xed4>
  402e16:	8b 65 ac             	mov    -0x54(%ebp),%esp
  402e19:	e9 e2 fe ff ff       	jmp    402d00 <.text+0xc60>
  402e1e:	89 45 d4             	mov    %eax,-0x2c(%ebp)
  402e21:	e9 42 fc ff ff       	jmp    402a68 <.text+0x9c8>
  402e26:	8d 45 d8             	lea    -0x28(%ebp),%eax
  402e29:	8b 55 d0             	mov    -0x30(%ebp),%edx
  402e2c:	89 04 24             	mov    %eax,(%esp)
  402e2f:	8b 4d c8             	mov    -0x38(%ebp),%ecx
  402e32:	8b 45 c0             	mov    -0x40(%ebp),%eax
  402e35:	80 ce 80             	or     $0x80,%dh
  402e38:	e8 63 f9 ff ff       	call   4027a0 <.text+0x700>
  402e3d:	89 45 d4             	mov    %eax,-0x2c(%ebp)
  402e40:	e9 5e fa ff ff       	jmp    4028a3 <.text+0x803>
  402e45:	8b 45 cc             	mov    -0x34(%ebp),%eax
  402e48:	89 04 24             	mov    %eax,(%esp)
  402e4b:	e8 70 0b 00 00       	call   4039c0 <___mingw_closedir>
  402e50:	8b 45 b0             	mov    -0x50(%ebp),%eax
  402e53:	85 c0                	test   %eax,%eax
  402e55:	0f 84 44 fe ff ff    	je     402c9f <.text+0xbff>
  402e5b:	8b 55 08             	mov    0x8(%ebp),%edx
  402e5e:	8b 45 b0             	mov    -0x50(%ebp),%eax
  402e61:	e8 9a f8 ff ff       	call   402700 <.text+0x660>
  402e66:	e9 34 fe ff ff       	jmp    402c9f <.text+0xbff>
  402e6b:	89 34 24             	mov    %esi,(%esp)
  402e6e:	e8 01 0f 00 00       	call   403d74 <_strdup>
  402e73:	89 dc                	mov    %ebx,%esp
  402e75:	85 c0                	test   %eax,%eax
  402e77:	74 24                	je     402e9d <.text+0xdfd>
  402e79:	8b 55 08             	mov    0x8(%ebp),%edx
  402e7c:	85 d2                	test   %edx,%edx
  402e7e:	74 1d                	je     402e9d <.text+0xdfd>
  402e80:	8b 55 08             	mov    0x8(%ebp),%edx
  402e83:	e8 18 f8 ff ff       	call   4026a0 <.text+0x600>
  402e88:	8b 45 e0             	mov    -0x20(%ebp),%eax
  402e8b:	89 c7                	mov    %eax,%edi
  402e8d:	89 3c 24             	mov    %edi,(%esp)
  402e90:	e8 db f1 ff ff       	call   402070 <___mingw_aligned_free>
  402e95:	8b 65 bc             	mov    -0x44(%ebp),%esp
  402e98:	e9 ce fb ff ff       	jmp    402a6b <.text+0x9cb>
  402e9d:	8b 45 e0             	mov    -0x20(%ebp),%eax
  402ea0:	89 c7                	mov    %eax,%edi
  402ea2:	eb e9                	jmp    402e8d <.text+0xded>
  402ea4:	8b 75 b4             	mov    -0x4c(%ebp),%esi
  402ea7:	8b 03                	mov    (%ebx),%eax
  402ea9:	89 4d 98             	mov    %ecx,-0x68(%ebp)
  402eac:	89 14 24             	mov    %edx,(%esp)
  402eaf:	89 74 24 08          	mov    %esi,0x8(%esp)
  402eb3:	89 44 24 04          	mov    %eax,0x4(%esp)
  402eb7:	89 55 a4             	mov    %edx,-0x5c(%ebp)
  402eba:	e8 05 0f 00 00       	call   403dc4 <_memcpy>
  402ebf:	0f b6 44 34 0b       	movzbl 0xb(%esp,%esi,1),%eax
  402ec4:	8b 55 a4             	mov    -0x5c(%ebp),%edx
  402ec7:	8b 4d 98             	mov    -0x68(%ebp),%ecx
  402eca:	3c 2f                	cmp    $0x2f,%al
  402ecc:	0f 84 b1 00 00 00    	je     402f83 <.text+0xee3>
  402ed2:	3c 5c                	cmp    $0x5c,%al
  402ed4:	0f 84 a9 00 00 00    	je     402f83 <.text+0xee3>
  402eda:	8b 75 b4             	mov    -0x4c(%ebp),%esi
  402edd:	0f b6 45 9f          	movzbl -0x61(%ebp),%eax
  402ee1:	88 04 32             	mov    %al,(%edx,%esi,1)
  402ee4:	8d 44 32 01          	lea    0x1(%edx,%esi,1),%eax
  402ee8:	e9 78 fe ff ff       	jmp    402d65 <.text+0xcc5>
  402eed:	8b 7d b0             	mov    -0x50(%ebp),%edi
  402ef0:	85 ff                	test   %edi,%edi
  402ef2:	0f 84 ff 00 00 00    	je     402ff7 <.text+0xf57>
  402ef8:	8b 45 d0             	mov    -0x30(%ebp),%eax
  402efb:	89 5d a8             	mov    %ebx,-0x58(%ebp)
  402efe:	25 00 40 00 00       	and    $0x4000,%eax
  402f03:	89 c3                	mov    %eax,%ebx
  402f05:	eb 1f                	jmp    402f26 <.text+0xe86>
  402f07:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  402f0e:	66 90                	xchg   %ax,%ax
  402f10:	e8 87 0e 00 00       	call   403d9c <_strcoll>
  402f15:	8b 0f                	mov    (%edi),%ecx
  402f17:	8b 57 04             	mov    0x4(%edi),%edx
  402f1a:	85 c0                	test   %eax,%eax
  402f1c:	7f 02                	jg     402f20 <.text+0xe80>
  402f1e:	89 ca                	mov    %ecx,%edx
  402f20:	85 d2                	test   %edx,%edx
  402f22:	74 17                	je     402f3b <.text+0xe9b>
  402f24:	89 d7                	mov    %edx,%edi
  402f26:	8b 47 08             	mov    0x8(%edi),%eax
  402f29:	89 34 24             	mov    %esi,(%esp)
  402f2c:	89 44 24 04          	mov    %eax,0x4(%esp)
  402f30:	85 db                	test   %ebx,%ebx
  402f32:	75 dc                	jne    402f10 <.text+0xe70>
  402f34:	e8 33 0e 00 00       	call   403d6c <_stricoll>
  402f39:	eb da                	jmp    402f15 <.text+0xe75>
  402f3b:	8b 5d a8             	mov    -0x58(%ebp),%ebx
  402f3e:	89 45 a8             	mov    %eax,-0x58(%ebp)
  402f41:	c7 04 24 0c 00 00 00 	movl   $0xc,(%esp)
  402f48:	e8 87 0e 00 00       	call   403dd4 <_malloc>
  402f4d:	8b 55 a8             	mov    -0x58(%ebp),%edx
  402f50:	85 c0                	test   %eax,%eax
  402f52:	0f 84 be fe ff ff    	je     402e16 <.text+0xd76>
  402f58:	89 70 08             	mov    %esi,0x8(%eax)
  402f5b:	c7 40 04 00 00 00 00 	movl   $0x0,0x4(%eax)
  402f62:	c7 00 00 00 00 00    	movl   $0x0,(%eax)
  402f68:	85 d2                	test   %edx,%edx
  402f6a:	7e 21                	jle    402f8d <.text+0xeed>
  402f6c:	89 47 04             	mov    %eax,0x4(%edi)
  402f6f:	e9 a2 fe ff ff       	jmp    402e16 <.text+0xd76>
  402f74:	8b 55 08             	mov    0x8(%ebp),%edx
  402f77:	89 f0                	mov    %esi,%eax
  402f79:	e8 22 f7 ff ff       	call   4026a0 <.text+0x600>
  402f7e:	e9 93 fe ff ff       	jmp    402e16 <.text+0xd76>
  402f83:	8b 45 b4             	mov    -0x4c(%ebp),%eax
  402f86:	01 d0                	add    %edx,%eax
  402f88:	e9 d8 fd ff ff       	jmp    402d65 <.text+0xcc5>
  402f8d:	89 07                	mov    %eax,(%edi)
  402f8f:	e9 82 fe ff ff       	jmp    402e16 <.text+0xd76>
  402f94:	8b 7d c4             	mov    -0x3c(%ebp),%edi
  402f97:	8b 55 d0             	mov    -0x30(%ebp),%edx
  402f9a:	89 f8                	mov    %edi,%eax
  402f9c:	e8 5f f6 ff ff       	call   402600 <.text+0x560>
  402fa1:	89 45 d4             	mov    %eax,-0x2c(%ebp)
  402fa4:	85 c0                	test   %eax,%eax
  402fa6:	74 08                	je     402fb0 <.text+0xf10>
  402fa8:	8b 5d c4             	mov    -0x3c(%ebp),%ebx
  402fab:	e9 35 f9 ff ff       	jmp    4028e5 <.text+0x845>
  402fb0:	89 3c 24             	mov    %edi,(%esp)
  402fb3:	89 e3                	mov    %esp,%ebx
  402fb5:	e8 da 0d 00 00       	call   403d94 <_strlen>
  402fba:	83 c0 10             	add    $0x10,%eax
  402fbd:	c1 e8 04             	shr    $0x4,%eax
  402fc0:	c1 e0 04             	shl    $0x4,%eax
  402fc3:	e8 78 0d 00 00       	call   403d40 <___chkstk_ms>
  402fc8:	29 c4                	sub    %eax,%esp
  402fca:	89 f9                	mov    %edi,%ecx
  402fcc:	8d 74 24 0c          	lea    0xc(%esp),%esi
  402fd0:	89 f2                	mov    %esi,%edx
  402fd2:	eb 10                	jmp    402fe4 <.text+0xf44>
  402fd4:	89 f9                	mov    %edi,%ecx
  402fd6:	83 c2 01             	add    $0x1,%edx
  402fd9:	88 42 ff             	mov    %al,-0x1(%edx)
  402fdc:	84 c0                	test   %al,%al
  402fde:	0f 84 87 fe ff ff    	je     402e6b <.text+0xdcb>
  402fe4:	0f b6 01             	movzbl (%ecx),%eax
  402fe7:	8d 79 01             	lea    0x1(%ecx),%edi
  402fea:	3c 7f                	cmp    $0x7f,%al
  402fec:	75 e6                	jne    402fd4 <.text+0xf34>
  402fee:	0f b6 41 01          	movzbl 0x1(%ecx),%eax
  402ff2:	83 c1 02             	add    $0x2,%ecx
  402ff5:	eb df                	jmp    402fd6 <.text+0xf36>
  402ff7:	c7 04 24 0c 00 00 00 	movl   $0xc,(%esp)
  402ffe:	e8 d1 0d 00 00       	call   403dd4 <_malloc>
  403003:	89 45 b0             	mov    %eax,-0x50(%ebp)
  403006:	85 c0                	test   %eax,%eax
  403008:	0f 84 08 fe ff ff    	je     402e16 <.text+0xd76>
  40300e:	8b 45 b0             	mov    -0x50(%ebp),%eax
  403011:	89 70 08             	mov    %esi,0x8(%eax)
  403014:	c7 40 04 00 00 00 00 	movl   $0x0,0x4(%eax)
  40301b:	c7 00 00 00 00 00    	movl   $0x0,(%eax)
  403021:	e9 f0 fd ff ff       	jmp    402e16 <.text+0xd76>
  403026:	c7 45 d4 03 00 00 00 	movl   $0x3,-0x2c(%ebp)
  40302d:	e9 e4 fd ff ff       	jmp    402e16 <.text+0xd76>
  403032:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  403039:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi

00403040 <___mingw_glob>:
  403040:	55                   	push   %ebp
  403041:	89 e5                	mov    %esp,%ebp
  403043:	57                   	push   %edi
  403044:	56                   	push   %esi
  403045:	53                   	push   %ebx
  403046:	83 ec 2c             	sub    $0x2c,%esp
  403049:	8b 75 14             	mov    0x14(%ebp),%esi
  40304c:	8b 5d 08             	mov    0x8(%ebp),%ebx
  40304f:	8b 7d 0c             	mov    0xc(%ebp),%edi
  403052:	85 f6                	test   %esi,%esi
  403054:	74 08                	je     40305e <___mingw_glob+0x1e>
  403056:	f7 c7 02 00 00 00    	test   $0x2,%edi
  40305c:	74 3a                	je     403098 <___mingw_glob+0x58>
  40305e:	81 3e 04 52 40 00    	cmpl   $0x405204,(%esi)
  403064:	74 0d                	je     403073 <___mingw_glob+0x33>
  403066:	89 f0                	mov    %esi,%eax
  403068:	e8 e3 f6 ff ff       	call   402750 <.text+0x6b0>
  40306d:	c7 06 04 52 40 00    	movl   $0x405204,(%esi)
  403073:	89 34 24             	mov    %esi,(%esp)
  403076:	8b 4d 10             	mov    0x10(%ebp),%ecx
  403079:	89 fa                	mov    %edi,%edx
  40307b:	89 d8                	mov    %ebx,%eax
  40307d:	e8 1e f7 ff ff       	call   4027a0 <.text+0x700>
  403082:	89 c1                	mov    %eax,%ecx
  403084:	83 f8 02             	cmp    $0x2,%eax
  403087:	74 1f                	je     4030a8 <___mingw_glob+0x68>
  403089:	8d 65 f4             	lea    -0xc(%ebp),%esp
  40308c:	89 c8                	mov    %ecx,%eax
  40308e:	5b                   	pop    %ebx
  40308f:	5e                   	pop    %esi
  403090:	5f                   	pop    %edi
  403091:	5d                   	pop    %ebp
  403092:	c3                   	ret    
  403093:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  403097:	90                   	nop
  403098:	c7 46 0c 00 00 00 00 	movl   $0x0,0xc(%esi)
  40309f:	eb bd                	jmp    40305e <___mingw_glob+0x1e>
  4030a1:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  4030a8:	83 e7 10             	and    $0x10,%edi
  4030ab:	74 dc                	je     403089 <___mingw_glob+0x49>
  4030ad:	89 45 dc             	mov    %eax,-0x24(%ebp)
  4030b0:	89 65 e4             	mov    %esp,-0x1c(%ebp)
  4030b3:	89 1c 24             	mov    %ebx,(%esp)
  4030b6:	e8 d9 0c 00 00       	call   403d94 <_strlen>
  4030bb:	83 c0 10             	add    $0x10,%eax
  4030be:	c1 e8 04             	shr    $0x4,%eax
  4030c1:	c1 e0 04             	shl    $0x4,%eax
  4030c4:	e8 77 0c 00 00       	call   403d40 <___chkstk_ms>
  4030c9:	8b 4d dc             	mov    -0x24(%ebp),%ecx
  4030cc:	29 c4                	sub    %eax,%esp
  4030ce:	8d 44 24 04          	lea    0x4(%esp),%eax
  4030d2:	89 45 e0             	mov    %eax,-0x20(%ebp)
  4030d5:	89 c2                	mov    %eax,%edx
  4030d7:	eb 13                	jmp    4030ec <___mingw_glob+0xac>
  4030d9:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  4030e0:	83 c2 01             	add    $0x1,%edx
  4030e3:	89 fb                	mov    %edi,%ebx
  4030e5:	88 42 ff             	mov    %al,-0x1(%edx)
  4030e8:	84 c0                	test   %al,%al
  4030ea:	74 1b                	je     403107 <___mingw_glob+0xc7>
  4030ec:	0f b6 03             	movzbl (%ebx),%eax
  4030ef:	8d 7b 01             	lea    0x1(%ebx),%edi
  4030f2:	3c 7f                	cmp    $0x7f,%al
  4030f4:	75 ea                	jne    4030e0 <___mingw_glob+0xa0>
  4030f6:	0f b6 43 01          	movzbl 0x1(%ebx),%eax
  4030fa:	83 c2 01             	add    $0x1,%edx
  4030fd:	83 c3 02             	add    $0x2,%ebx
  403100:	88 42 ff             	mov    %al,-0x1(%edx)
  403103:	84 c0                	test   %al,%al
  403105:	75 e5                	jne    4030ec <___mingw_glob+0xac>
  403107:	8b 45 e0             	mov    -0x20(%ebp),%eax
  40310a:	89 4d dc             	mov    %ecx,-0x24(%ebp)
  40310d:	89 04 24             	mov    %eax,(%esp)
  403110:	e8 5f 0c 00 00       	call   403d74 <_strdup>
  403115:	8b 65 e4             	mov    -0x1c(%ebp),%esp
  403118:	8b 4d dc             	mov    -0x24(%ebp),%ecx
  40311b:	85 c0                	test   %eax,%eax
  40311d:	0f 84 66 ff ff ff    	je     403089 <___mingw_glob+0x49>
  403123:	89 f2                	mov    %esi,%edx
  403125:	89 4d e4             	mov    %ecx,-0x1c(%ebp)
  403128:	e8 73 f5 ff ff       	call   4026a0 <.text+0x600>
  40312d:	8b 4d e4             	mov    -0x1c(%ebp),%ecx
  403130:	e9 54 ff ff ff       	jmp    403089 <___mingw_glob+0x49>
  403135:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  40313c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi

00403140 <___mingw_globfree>:
  403140:	57                   	push   %edi
  403141:	56                   	push   %esi
  403142:	53                   	push   %ebx
  403143:	83 ec 10             	sub    $0x10,%esp
  403146:	8b 74 24 20          	mov    0x20(%esp),%esi
  40314a:	81 3e 04 52 40 00    	cmpl   $0x405204,(%esi)
  403150:	74 0e                	je     403160 <___mingw_globfree+0x20>
  403152:	83 c4 10             	add    $0x10,%esp
  403155:	5b                   	pop    %ebx
  403156:	5e                   	pop    %esi
  403157:	5f                   	pop    %edi
  403158:	c3                   	ret    
  403159:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  403160:	8b 7e 04             	mov    0x4(%esi),%edi
  403163:	8b 5e 0c             	mov    0xc(%esi),%ebx
  403166:	85 ff                	test   %edi,%edi
  403168:	7e 1b                	jle    403185 <___mingw_globfree+0x45>
  40316a:	01 df                	add    %ebx,%edi
  40316c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  403170:	8b 46 08             	mov    0x8(%esi),%eax
  403173:	8b 04 98             	mov    (%eax,%ebx,4),%eax
  403176:	83 c3 01             	add    $0x1,%ebx
  403179:	89 04 24             	mov    %eax,(%esp)
  40317c:	e8 ef ee ff ff       	call   402070 <___mingw_aligned_free>
  403181:	39 df                	cmp    %ebx,%edi
  403183:	75 eb                	jne    403170 <___mingw_globfree+0x30>
  403185:	8b 46 08             	mov    0x8(%esi),%eax
  403188:	89 44 24 20          	mov    %eax,0x20(%esp)
  40318c:	83 c4 10             	add    $0x10,%esp
  40318f:	5b                   	pop    %ebx
  403190:	5e                   	pop    %esi
  403191:	5f                   	pop    %edi
  403192:	e9 d9 ee ff ff       	jmp    402070 <___mingw_aligned_free>
  403197:	90                   	nop
  403198:	90                   	nop
  403199:	90                   	nop
  40319a:	90                   	nop
  40319b:	90                   	nop
  40319c:	90                   	nop
  40319d:	90                   	nop
  40319e:	90                   	nop
  40319f:	90                   	nop

004031a0 <___mingw_dirname>:
  4031a0:	55                   	push   %ebp
  4031a1:	89 e5                	mov    %esp,%ebp
  4031a3:	57                   	push   %edi
  4031a4:	56                   	push   %esi
  4031a5:	53                   	push   %ebx
  4031a6:	83 ec 2c             	sub    $0x2c,%esp
  4031a9:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
  4031b0:	00 
  4031b1:	c7 04 24 02 00 00 00 	movl   $0x2,(%esp)
  4031b8:	e8 ef 0b 00 00       	call   403dac <_setlocale>
  4031bd:	89 c3                	mov    %eax,%ebx
  4031bf:	85 c0                	test   %eax,%eax
  4031c1:	74 0a                	je     4031cd <___mingw_dirname+0x2d>
  4031c3:	89 04 24             	mov    %eax,(%esp)
  4031c6:	e8 a9 0b 00 00       	call   403d74 <_strdup>
  4031cb:	89 c3                	mov    %eax,%ebx
  4031cd:	c7 44 24 04 18 52 40 	movl   $0x405218,0x4(%esp)
  4031d4:	00 
  4031d5:	c7 04 24 02 00 00 00 	movl   $0x2,(%esp)
  4031dc:	e8 cb 0b 00 00       	call   403dac <_setlocale>
  4031e1:	8b 4d 08             	mov    0x8(%ebp),%ecx
  4031e4:	85 c9                	test   %ecx,%ecx
  4031e6:	74 08                	je     4031f0 <___mingw_dirname+0x50>
  4031e8:	8b 45 08             	mov    0x8(%ebp),%eax
  4031eb:	80 38 00             	cmpb   $0x0,(%eax)
  4031ee:	75 78                	jne    403268 <___mingw_dirname+0xc8>
  4031f0:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
  4031f7:	00 
  4031f8:	c7 44 24 04 1a 52 40 	movl   $0x40521a,0x4(%esp)
  4031ff:	00 
  403200:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
  403207:	e8 70 0b 00 00       	call   403d7c <_wcstombs>
  40320c:	8d 70 01             	lea    0x1(%eax),%esi
  40320f:	89 74 24 04          	mov    %esi,0x4(%esp)
  403213:	a1 68 70 40 00       	mov    0x407068,%eax
  403218:	89 04 24             	mov    %eax,(%esp)
  40321b:	e8 c0 09 00 00       	call   403be0 <___mingw_realloc>
  403220:	a3 68 70 40 00       	mov    %eax,0x407068
  403225:	89 74 24 08          	mov    %esi,0x8(%esp)
  403229:	c7 44 24 04 1a 52 40 	movl   $0x40521a,0x4(%esp)
  403230:	00 
  403231:	89 04 24             	mov    %eax,(%esp)
  403234:	e8 43 0b 00 00       	call   403d7c <_wcstombs>
  403239:	89 5c 24 04          	mov    %ebx,0x4(%esp)
  40323d:	c7 04 24 02 00 00 00 	movl   $0x2,(%esp)
  403244:	e8 63 0b 00 00       	call   403dac <_setlocale>
  403249:	89 1c 24             	mov    %ebx,(%esp)
  40324c:	e8 1f ee ff ff       	call   402070 <___mingw_aligned_free>
  403251:	8b 35 68 70 40 00    	mov    0x407068,%esi
  403257:	8d 65 f4             	lea    -0xc(%ebp),%esp
  40325a:	89 f0                	mov    %esi,%eax
  40325c:	5b                   	pop    %ebx
  40325d:	5e                   	pop    %esi
  40325e:	5f                   	pop    %edi
  40325f:	5d                   	pop    %ebp
  403260:	c3                   	ret    
  403261:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  403268:	89 65 dc             	mov    %esp,-0x24(%ebp)
  40326b:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
  403272:	00 
  403273:	8b 45 08             	mov    0x8(%ebp),%eax
  403276:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
  40327d:	89 44 24 04          	mov    %eax,0x4(%esp)
  403281:	e8 46 0b 00 00       	call   403dcc <_mbstowcs>
  403286:	89 c2                	mov    %eax,%edx
  403288:	8d 44 00 11          	lea    0x11(%eax,%eax,1),%eax
  40328c:	c1 e8 04             	shr    $0x4,%eax
  40328f:	c1 e0 04             	shl    $0x4,%eax
  403292:	e8 a9 0a 00 00       	call   403d40 <___chkstk_ms>
  403297:	29 c4                	sub    %eax,%esp
  403299:	89 54 24 08          	mov    %edx,0x8(%esp)
  40329d:	8b 45 08             	mov    0x8(%ebp),%eax
  4032a0:	8d 7c 24 0c          	lea    0xc(%esp),%edi
  4032a4:	89 3c 24             	mov    %edi,(%esp)
  4032a7:	89 44 24 04          	mov    %eax,0x4(%esp)
  4032ab:	e8 1c 0b 00 00       	call   403dcc <_mbstowcs>
  4032b0:	31 d2                	xor    %edx,%edx
  4032b2:	83 f8 01             	cmp    $0x1,%eax
  4032b5:	89 45 d8             	mov    %eax,-0x28(%ebp)
  4032b8:	66 89 14 47          	mov    %dx,(%edi,%eax,2)
  4032bc:	0f b7 07             	movzwl (%edi),%eax
  4032bf:	76 3f                	jbe    403300 <___mingw_dirname+0x160>
  4032c1:	89 c1                	mov    %eax,%ecx
  4032c3:	66 89 45 e2          	mov    %ax,-0x1e(%ebp)
  4032c7:	0f b7 47 02          	movzwl 0x2(%edi),%eax
  4032cb:	89 7d e4             	mov    %edi,-0x1c(%ebp)
  4032ce:	66 83 f9 2f          	cmp    $0x2f,%cx
  4032d2:	0f 84 08 02 00 00    	je     4034e0 <___mingw_dirname+0x340>
  4032d8:	66 83 f9 5c          	cmp    $0x5c,%cx
  4032dc:	0f 84 fe 01 00 00    	je     4034e0 <___mingw_dirname+0x340>
  4032e2:	66 83 f8 3a          	cmp    $0x3a,%ax
  4032e6:	75 1f                	jne    403307 <___mingw_dirname+0x167>
  4032e8:	8d 47 04             	lea    0x4(%edi),%eax
  4032eb:	89 45 e4             	mov    %eax,-0x1c(%ebp)
  4032ee:	0f b7 47 04          	movzwl 0x4(%edi),%eax
  4032f2:	66 89 45 e2          	mov    %ax,-0x1e(%ebp)
  4032f6:	eb 0f                	jmp    403307 <___mingw_dirname+0x167>
  4032f8:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  4032ff:	90                   	nop
  403300:	66 89 45 e2          	mov    %ax,-0x1e(%ebp)
  403304:	89 7d e4             	mov    %edi,-0x1c(%ebp)
  403307:	66 83 7d e2 00       	cmpw   $0x0,-0x1e(%ebp)
  40330c:	75 12                	jne    403320 <___mingw_dirname+0x180>
  40330e:	8b 65 dc             	mov    -0x24(%ebp),%esp
  403311:	e9 da fe ff ff       	jmp    4031f0 <___mingw_dirname+0x50>
  403316:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  40331d:	8d 76 00             	lea    0x0(%esi),%esi
  403320:	8b 45 e4             	mov    -0x1c(%ebp),%eax
  403323:	0f b7 55 e2          	movzwl -0x1e(%ebp),%edx
  403327:	89 c1                	mov    %eax,%ecx
  403329:	eb 19                	jmp    403344 <___mingw_dirname+0x1a4>
  40332b:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  40332f:	90                   	nop
  403330:	89 c6                	mov    %eax,%esi
  403332:	66 83 fa 5c          	cmp    $0x5c,%dx
  403336:	74 23                	je     40335b <___mingw_dirname+0x1bb>
  403338:	0f b7 56 02          	movzwl 0x2(%esi),%edx
  40333c:	83 c0 02             	add    $0x2,%eax
  40333f:	66 85 d2             	test   %dx,%dx
  403342:	74 34                	je     403378 <___mingw_dirname+0x1d8>
  403344:	66 83 fa 2f          	cmp    $0x2f,%dx
  403348:	75 e6                	jne    403330 <___mingw_dirname+0x190>
  40334a:	0f b7 10             	movzwl (%eax),%edx
  40334d:	66 83 fa 2f          	cmp    $0x2f,%dx
  403351:	75 11                	jne    403364 <___mingw_dirname+0x1c4>
  403353:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  403357:	90                   	nop
  403358:	83 c0 02             	add    $0x2,%eax
  40335b:	0f b7 10             	movzwl (%eax),%edx
  40335e:	66 83 fa 2f          	cmp    $0x2f,%dx
  403362:	74 f4                	je     403358 <___mingw_dirname+0x1b8>
  403364:	66 83 fa 5c          	cmp    $0x5c,%dx
  403368:	74 ee                	je     403358 <___mingw_dirname+0x1b8>
  40336a:	89 c6                	mov    %eax,%esi
  40336c:	66 85 d2             	test   %dx,%dx
  40336f:	74 07                	je     403378 <___mingw_dirname+0x1d8>
  403371:	89 c1                	mov    %eax,%ecx
  403373:	eb c3                	jmp    403338 <___mingw_dirname+0x198>
  403375:	8d 76 00             	lea    0x0(%esi),%esi
  403378:	39 4d e4             	cmp    %ecx,-0x1c(%ebp)
  40337b:	0f 82 8f 00 00 00    	jb     403410 <___mingw_dirname+0x270>
  403381:	0f b7 45 e2          	movzwl -0x1e(%ebp),%eax
  403385:	66 83 f8 2f          	cmp    $0x2f,%ax
  403389:	74 11                	je     40339c <___mingw_dirname+0x1fc>
  40338b:	66 83 f8 5c          	cmp    $0x5c,%ax
  40338f:	74 0b                	je     40339c <___mingw_dirname+0x1fc>
  403391:	8b 45 e4             	mov    -0x1c(%ebp),%eax
  403394:	b9 2e 00 00 00       	mov    $0x2e,%ecx
  403399:	66 89 08             	mov    %cx,(%eax)
  40339c:	8b 45 e4             	mov    -0x1c(%ebp),%eax
  40339f:	31 d2                	xor    %edx,%edx
  4033a1:	66 89 50 02          	mov    %dx,0x2(%eax)
  4033a5:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
  4033ac:	00 
  4033ad:	89 7c 24 04          	mov    %edi,0x4(%esp)
  4033b1:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
  4033b8:	e8 bf 09 00 00       	call   403d7c <_wcstombs>
  4033bd:	8d 50 01             	lea    0x1(%eax),%edx
  4033c0:	89 54 24 04          	mov    %edx,0x4(%esp)
  4033c4:	a1 68 70 40 00       	mov    0x407068,%eax
  4033c9:	89 55 e4             	mov    %edx,-0x1c(%ebp)
  4033cc:	89 04 24             	mov    %eax,(%esp)
  4033cf:	e8 0c 08 00 00       	call   403be0 <___mingw_realloc>
  4033d4:	8b 55 e4             	mov    -0x1c(%ebp),%edx
  4033d7:	a3 68 70 40 00       	mov    %eax,0x407068
  4033dc:	89 c6                	mov    %eax,%esi
  4033de:	89 54 24 08          	mov    %edx,0x8(%esp)
  4033e2:	89 7c 24 04          	mov    %edi,0x4(%esp)
  4033e6:	89 04 24             	mov    %eax,(%esp)
  4033e9:	e8 8e 09 00 00       	call   403d7c <_wcstombs>
  4033ee:	89 5c 24 04          	mov    %ebx,0x4(%esp)
  4033f2:	c7 04 24 02 00 00 00 	movl   $0x2,(%esp)
  4033f9:	e8 ae 09 00 00       	call   403dac <_setlocale>
  4033fe:	89 1c 24             	mov    %ebx,(%esp)
  403401:	e8 6a ec ff ff       	call   402070 <___mingw_aligned_free>
  403406:	8b 65 dc             	mov    -0x24(%ebp),%esp
  403409:	e9 49 fe ff ff       	jmp    403257 <___mingw_dirname+0xb7>
  40340e:	66 90                	xchg   %ax,%ax
  403410:	89 c8                	mov    %ecx,%eax
  403412:	83 e9 02             	sub    $0x2,%ecx
  403415:	39 4d e4             	cmp    %ecx,-0x1c(%ebp)
  403418:	0f 83 4d 01 00 00    	jae    40356b <___mingw_dirname+0x3cb>
  40341e:	0f b7 01             	movzwl (%ecx),%eax
  403421:	66 83 f8 2f          	cmp    $0x2f,%ax
  403425:	74 e9                	je     403410 <___mingw_dirname+0x270>
  403427:	66 83 f8 5c          	cmp    $0x5c,%ax
  40342b:	74 e3                	je     403410 <___mingw_dirname+0x270>
  40342d:	31 c0                	xor    %eax,%eax
  40342f:	66 89 41 02          	mov    %ax,0x2(%ecx)
  403433:	0f b7 07             	movzwl (%edi),%eax
  403436:	89 f9                	mov    %edi,%ecx
  403438:	66 83 f8 2f          	cmp    $0x2f,%ax
  40343c:	74 12                	je     403450 <___mingw_dirname+0x2b0>
  40343e:	66 83 f8 5c          	cmp    $0x5c,%ax
  403442:	0f 85 cd 00 00 00    	jne    403515 <___mingw_dirname+0x375>
  403448:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  40344f:	90                   	nop
  403450:	0f b7 51 02          	movzwl 0x2(%ecx),%edx
  403454:	83 c1 02             	add    $0x2,%ecx
  403457:	66 83 fa 2f          	cmp    $0x2f,%dx
  40345b:	74 f3                	je     403450 <___mingw_dirname+0x2b0>
  40345d:	66 83 fa 5c          	cmp    $0x5c,%dx
  403461:	74 ed                	je     403450 <___mingw_dirname+0x2b0>
  403463:	89 ca                	mov    %ecx,%edx
  403465:	29 fa                	sub    %edi,%edx
  403467:	83 fa 04             	cmp    $0x4,%edx
  40346a:	0f 8e a5 00 00 00    	jle    403515 <___mingw_dirname+0x375>
  403470:	89 f9                	mov    %edi,%ecx
  403472:	66 85 c0             	test   %ax,%ax
  403475:	0f 84 c0 00 00 00    	je     40353b <___mingw_dirname+0x39b>
  40347b:	89 5d e4             	mov    %ebx,-0x1c(%ebp)
  40347e:	89 ca                	mov    %ecx,%edx
  403480:	eb 24                	jmp    4034a6 <___mingw_dirname+0x306>
  403482:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  403488:	0f b7 5a 02          	movzwl 0x2(%edx),%ebx
  40348c:	8d 72 02             	lea    0x2(%edx),%esi
  40348f:	66 83 f8 5c          	cmp    $0x5c,%ax
  403493:	0f 84 97 00 00 00    	je     403530 <___mingw_dirname+0x390>
  403499:	89 d8                	mov    %ebx,%eax
  40349b:	89 f2                	mov    %esi,%edx
  40349d:	66 85 c0             	test   %ax,%ax
  4034a0:	0f 84 92 00 00 00    	je     403538 <___mingw_dirname+0x398>
  4034a6:	83 c1 02             	add    $0x2,%ecx
  4034a9:	66 89 41 fe          	mov    %ax,-0x2(%ecx)
  4034ad:	66 83 f8 2f          	cmp    $0x2f,%ax
  4034b1:	75 d5                	jne    403488 <___mingw_dirname+0x2e8>
  4034b3:	0f b7 1a             	movzwl (%edx),%ebx
  4034b6:	66 83 fb 5c          	cmp    $0x5c,%bx
  4034ba:	74 0c                	je     4034c8 <___mingw_dirname+0x328>
  4034bc:	89 d8                	mov    %ebx,%eax
  4034be:	66 83 fb 2f          	cmp    $0x2f,%bx
  4034c2:	75 d9                	jne    40349d <___mingw_dirname+0x2fd>
  4034c4:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  4034c8:	0f b7 42 02          	movzwl 0x2(%edx),%eax
  4034cc:	83 c2 02             	add    $0x2,%edx
  4034cf:	66 83 f8 2f          	cmp    $0x2f,%ax
  4034d3:	74 f3                	je     4034c8 <___mingw_dirname+0x328>
  4034d5:	66 83 f8 5c          	cmp    $0x5c,%ax
  4034d9:	74 ed                	je     4034c8 <___mingw_dirname+0x328>
  4034db:	eb c0                	jmp    40349d <___mingw_dirname+0x2fd>
  4034dd:	8d 76 00             	lea    0x0(%esi),%esi
  4034e0:	66 39 45 e2          	cmp    %ax,-0x1e(%ebp)
  4034e4:	0f 85 1d fe ff ff    	jne    403307 <___mingw_dirname+0x167>
  4034ea:	66 83 7f 04 00       	cmpw   $0x0,0x4(%edi)
  4034ef:	0f 85 12 fe ff ff    	jne    403307 <___mingw_dirname+0x167>
  4034f5:	89 5c 24 04          	mov    %ebx,0x4(%esp)
  4034f9:	c7 04 24 02 00 00 00 	movl   $0x2,(%esp)
  403500:	e8 a7 08 00 00       	call   403dac <_setlocale>
  403505:	89 1c 24             	mov    %ebx,(%esp)
  403508:	e8 63 eb ff ff       	call   402070 <___mingw_aligned_free>
  40350d:	8b 75 08             	mov    0x8(%ebp),%esi
  403510:	e9 f1 fe ff ff       	jmp    403406 <___mingw_dirname+0x266>
  403515:	66 39 47 02          	cmp    %ax,0x2(%edi)
  403519:	0f 85 51 ff ff ff    	jne    403470 <___mingw_dirname+0x2d0>
  40351f:	0f b7 01             	movzwl (%ecx),%eax
  403522:	e9 4b ff ff ff       	jmp    403472 <___mingw_dirname+0x2d2>
  403527:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  40352e:	66 90                	xchg   %ax,%ax
  403530:	89 f2                	mov    %esi,%edx
  403532:	eb 82                	jmp    4034b6 <___mingw_dirname+0x316>
  403534:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  403538:	8b 5d e4             	mov    -0x1c(%ebp),%ebx
  40353b:	8b 45 d8             	mov    -0x28(%ebp),%eax
  40353e:	31 f6                	xor    %esi,%esi
  403540:	66 89 31             	mov    %si,(%ecx)
  403543:	89 44 24 08          	mov    %eax,0x8(%esp)
  403547:	89 7c 24 04          	mov    %edi,0x4(%esp)
  40354b:	8b 45 08             	mov    0x8(%ebp),%eax
  40354e:	89 04 24             	mov    %eax,(%esp)
  403551:	e8 26 08 00 00       	call   403d7c <_wcstombs>
  403556:	8b 75 08             	mov    0x8(%ebp),%esi
  403559:	83 f8 ff             	cmp    $0xffffffff,%eax
  40355c:	0f 84 8c fe ff ff    	je     4033ee <___mingw_dirname+0x24e>
  403562:	c6 04 06 00          	movb   $0x0,(%esi,%eax,1)
  403566:	e9 83 fe ff ff       	jmp    4033ee <___mingw_dirname+0x24e>
  40356b:	0f 85 bc fe ff ff    	jne    40342d <___mingw_dirname+0x28d>
  403571:	0f b7 75 e2          	movzwl -0x1e(%ebp),%esi
  403575:	66 83 fe 2f          	cmp    $0x2f,%si
  403579:	74 0a                	je     403585 <___mingw_dirname+0x3e5>
  40357b:	66 83 fe 5c          	cmp    $0x5c,%si
  40357f:	0f 85 a8 fe ff ff    	jne    40342d <___mingw_dirname+0x28d>
  403585:	0f b7 75 e2          	movzwl -0x1e(%ebp),%esi
  403589:	66 39 71 02          	cmp    %si,0x2(%ecx)
  40358d:	0f 85 9a fe ff ff    	jne    40342d <___mingw_dirname+0x28d>
  403593:	0f b7 51 04          	movzwl 0x4(%ecx),%edx
  403597:	66 83 fa 2f          	cmp    $0x2f,%dx
  40359b:	0f 84 8c fe ff ff    	je     40342d <___mingw_dirname+0x28d>
  4035a1:	66 83 fa 5c          	cmp    $0x5c,%dx
  4035a5:	0f 84 82 fe ff ff    	je     40342d <___mingw_dirname+0x28d>
  4035ab:	89 c1                	mov    %eax,%ecx
  4035ad:	e9 7b fe ff ff       	jmp    40342d <___mingw_dirname+0x28d>
  4035b2:	90                   	nop
  4035b3:	90                   	nop
  4035b4:	90                   	nop
  4035b5:	90                   	nop
  4035b6:	90                   	nop
  4035b7:	90                   	nop
  4035b8:	90                   	nop
  4035b9:	90                   	nop
  4035ba:	90                   	nop
  4035bb:	90                   	nop
  4035bc:	90                   	nop
  4035bd:	90                   	nop
  4035be:	90                   	nop
  4035bf:	90                   	nop

004035c0 <.text>:
  4035c0:	56                   	push   %esi
  4035c1:	53                   	push   %ebx
  4035c2:	89 d3                	mov    %edx,%ebx
  4035c4:	81 ec 54 01 00 00    	sub    $0x154,%esp
  4035ca:	8d 54 24 10          	lea    0x10(%esp),%edx
  4035ce:	89 04 24             	mov    %eax,(%esp)
  4035d1:	89 54 24 04          	mov    %edx,0x4(%esp)
  4035d5:	e8 d2 08 00 00       	call   403eac <_FindFirstFileA@8>
  4035da:	83 ec 08             	sub    $0x8,%esp
  4035dd:	89 c6                	mov    %eax,%esi
  4035df:	83 f8 ff             	cmp    $0xffffffff,%eax
  4035e2:	74 74                	je     403658 <.text+0x98>
  4035e4:	31 c0                	xor    %eax,%eax
  4035e6:	8d 4b 0c             	lea    0xc(%ebx),%ecx
  4035e9:	66 89 43 06          	mov    %ax,0x6(%ebx)
  4035ed:	0f b6 44 24 3c       	movzbl 0x3c(%esp),%eax
  4035f2:	88 43 0c             	mov    %al,0xc(%ebx)
  4035f5:	84 c0                	test   %al,%al
  4035f7:	74 27                	je     403620 <.text+0x60>
  4035f9:	31 c0                	xor    %eax,%eax
  4035fb:	eb 07                	jmp    403604 <.text+0x44>
  4035fd:	8d 76 00             	lea    0x0(%esi),%esi
  403600:	0f b7 43 06          	movzwl 0x6(%ebx),%eax
  403604:	83 c0 01             	add    $0x1,%eax
  403607:	66 89 43 06          	mov    %ax,0x6(%ebx)
  40360b:	66 3d 04 01          	cmp    $0x104,%ax
  40360f:	0f b7 c0             	movzwl %ax,%eax
  403612:	0f b6 44 04 3c       	movzbl 0x3c(%esp,%eax,1),%eax
  403617:	83 d1 00             	adc    $0x0,%ecx
  40361a:	88 01                	mov    %al,(%ecx)
  40361c:	84 c0                	test   %al,%al
  40361e:	75 e0                	jne    403600 <.text+0x40>
  403620:	8b 44 24 10          	mov    0x10(%esp),%eax
  403624:	24 58                	and    $0x58,%al
  403626:	83 f8 10             	cmp    $0x10,%eax
  403629:	77 15                	ja     403640 <.text+0x80>
  40362b:	89 43 08             	mov    %eax,0x8(%ebx)
  40362e:	81 c4 54 01 00 00    	add    $0x154,%esp
  403634:	89 f0                	mov    %esi,%eax
  403636:	5b                   	pop    %ebx
  403637:	5e                   	pop    %esi
  403638:	c3                   	ret    
  403639:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  403640:	c7 43 08 18 00 00 00 	movl   $0x18,0x8(%ebx)
  403647:	81 c4 54 01 00 00    	add    $0x154,%esp
  40364d:	89 f0                	mov    %esi,%eax
  40364f:	5b                   	pop    %ebx
  403650:	5e                   	pop    %esi
  403651:	c3                   	ret    
  403652:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  403658:	e8 2f 08 00 00       	call   403e8c <_GetLastError@0>
  40365d:	89 c3                	mov    %eax,%ebx
  40365f:	e8 b8 07 00 00       	call   403e1c <__errno>
  403664:	89 18                	mov    %ebx,(%eax)
  403666:	83 fb 03             	cmp    $0x3,%ebx
  403669:	74 24                	je     40368f <.text+0xcf>
  40366b:	e8 ac 07 00 00       	call   403e1c <__errno>
  403670:	81 38 0b 01 00 00    	cmpl   $0x10b,(%eax)
  403676:	74 24                	je     40369c <.text+0xdc>
  403678:	e8 9f 07 00 00       	call   403e1c <__errno>
  40367d:	83 38 02             	cmpl   $0x2,(%eax)
  403680:	74 ac                	je     40362e <.text+0x6e>
  403682:	e8 95 07 00 00       	call   403e1c <__errno>
  403687:	c7 00 16 00 00 00    	movl   $0x16,(%eax)
  40368d:	eb 9f                	jmp    40362e <.text+0x6e>
  40368f:	e8 88 07 00 00       	call   403e1c <__errno>
  403694:	c7 00 02 00 00 00    	movl   $0x2,(%eax)
  40369a:	eb 92                	jmp    40362e <.text+0x6e>
  40369c:	e8 7b 07 00 00       	call   403e1c <__errno>
  4036a1:	c7 00 14 00 00 00    	movl   $0x14,(%eax)
  4036a7:	eb 85                	jmp    40362e <.text+0x6e>
  4036a9:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  4036b0:	56                   	push   %esi
  4036b1:	53                   	push   %ebx
  4036b2:	89 d3                	mov    %edx,%ebx
  4036b4:	81 ec 54 01 00 00    	sub    $0x154,%esp
  4036ba:	8d 54 24 10          	lea    0x10(%esp),%edx
  4036be:	89 04 24             	mov    %eax,(%esp)
  4036c1:	89 54 24 04          	mov    %edx,0x4(%esp)
  4036c5:	e8 da 07 00 00       	call   403ea4 <_FindNextFileA@8>
  4036ca:	83 ec 08             	sub    $0x8,%esp
  4036cd:	89 c6                	mov    %eax,%esi
  4036cf:	85 c0                	test   %eax,%eax
  4036d1:	74 75                	je     403748 <.text+0x188>
  4036d3:	31 c0                	xor    %eax,%eax
  4036d5:	8d 4b 0c             	lea    0xc(%ebx),%ecx
  4036d8:	66 89 43 06          	mov    %ax,0x6(%ebx)
  4036dc:	0f b6 44 24 3c       	movzbl 0x3c(%esp),%eax
  4036e1:	88 43 0c             	mov    %al,0xc(%ebx)
  4036e4:	84 c0                	test   %al,%al
  4036e6:	74 28                	je     403710 <.text+0x150>
  4036e8:	31 c0                	xor    %eax,%eax
  4036ea:	eb 08                	jmp    4036f4 <.text+0x134>
  4036ec:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  4036f0:	0f b7 43 06          	movzwl 0x6(%ebx),%eax
  4036f4:	83 c0 01             	add    $0x1,%eax
  4036f7:	66 89 43 06          	mov    %ax,0x6(%ebx)
  4036fb:	66 3d 04 01          	cmp    $0x104,%ax
  4036ff:	0f b7 c0             	movzwl %ax,%eax
  403702:	0f b6 44 04 3c       	movzbl 0x3c(%esp,%eax,1),%eax
  403707:	83 d1 00             	adc    $0x0,%ecx
  40370a:	88 01                	mov    %al,(%ecx)
  40370c:	84 c0                	test   %al,%al
  40370e:	75 e0                	jne    4036f0 <.text+0x130>
  403710:	8b 44 24 10          	mov    0x10(%esp),%eax
  403714:	24 58                	and    $0x58,%al
  403716:	83 f8 10             	cmp    $0x10,%eax
  403719:	77 15                	ja     403730 <.text+0x170>
  40371b:	89 43 08             	mov    %eax,0x8(%ebx)
  40371e:	81 c4 54 01 00 00    	add    $0x154,%esp
  403724:	89 f0                	mov    %esi,%eax
  403726:	5b                   	pop    %ebx
  403727:	5e                   	pop    %esi
  403728:	c3                   	ret    
  403729:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  403730:	c7 43 08 18 00 00 00 	movl   $0x18,0x8(%ebx)
  403737:	81 c4 54 01 00 00    	add    $0x154,%esp
  40373d:	89 f0                	mov    %esi,%eax
  40373f:	5b                   	pop    %ebx
  403740:	5e                   	pop    %esi
  403741:	c3                   	ret    
  403742:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  403748:	e8 3f 07 00 00       	call   403e8c <_GetLastError@0>
  40374d:	83 f8 12             	cmp    $0x12,%eax
  403750:	74 cc                	je     40371e <.text+0x15e>
  403752:	e8 c5 06 00 00       	call   403e1c <__errno>
  403757:	c7 00 02 00 00 00    	movl   $0x2,(%eax)
  40375d:	81 c4 54 01 00 00    	add    $0x154,%esp
  403763:	89 f0                	mov    %esi,%eax
  403765:	5b                   	pop    %ebx
  403766:	5e                   	pop    %esi
  403767:	c3                   	ret    
  403768:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  40376f:	90                   	nop

00403770 <___mingw_opendir>:
  403770:	55                   	push   %ebp
  403771:	57                   	push   %edi
  403772:	56                   	push   %esi
  403773:	53                   	push   %ebx
  403774:	81 ec 2c 01 00 00    	sub    $0x12c,%esp
  40377a:	8b 84 24 40 01 00 00 	mov    0x140(%esp),%eax
  403781:	85 c0                	test   %eax,%eax
  403783:	0f 84 af 01 00 00    	je     403938 <___mingw_opendir+0x1c8>
  403789:	80 38 00             	cmpb   $0x0,(%eax)
  40378c:	0f 84 86 01 00 00    	je     403918 <___mingw_opendir+0x1a8>
  403792:	8d 74 24 1c          	lea    0x1c(%esp),%esi
  403796:	c7 44 24 08 04 01 00 	movl   $0x104,0x8(%esp)
  40379d:	00 
  40379e:	89 44 24 04          	mov    %eax,0x4(%esp)
  4037a2:	89 34 24             	mov    %esi,(%esp)
  4037a5:	e8 6a 06 00 00       	call   403e14 <__fullpath>
  4037aa:	80 7c 24 1c 00       	cmpb   $0x0,0x1c(%esp)
  4037af:	89 f2                	mov    %esi,%edx
  4037b1:	74 4d                	je     403800 <___mingw_opendir+0x90>
  4037b3:	8b 0a                	mov    (%edx),%ecx
  4037b5:	83 c2 04             	add    $0x4,%edx
  4037b8:	8d 81 ff fe fe fe    	lea    -0x1010101(%ecx),%eax
  4037be:	f7 d1                	not    %ecx
  4037c0:	21 c8                	and    %ecx,%eax
  4037c2:	25 80 80 80 80       	and    $0x80808080,%eax
  4037c7:	74 ea                	je     4037b3 <___mingw_opendir+0x43>
  4037c9:	a9 80 80 00 00       	test   $0x8080,%eax
  4037ce:	0f 84 34 01 00 00    	je     403908 <___mingw_opendir+0x198>
  4037d4:	89 c3                	mov    %eax,%ebx
  4037d6:	00 c3                	add    %al,%bl
  4037d8:	83 da 03             	sbb    $0x3,%edx
  4037db:	29 f2                	sub    %esi,%edx
  4037dd:	0f b6 4c 14 1b       	movzbl 0x1b(%esp,%edx,1),%ecx
  4037e2:	8d 04 16             	lea    (%esi,%edx,1),%eax
  4037e5:	80 f9 2f             	cmp    $0x2f,%cl
  4037e8:	74 40                	je     40382a <___mingw_opendir+0xba>
  4037ea:	80 f9 5c             	cmp    $0x5c,%cl
  4037ed:	74 3b                	je     40382a <___mingw_opendir+0xba>
  4037ef:	b9 5c 00 00 00       	mov    $0x5c,%ecx
  4037f4:	66 89 08             	mov    %cx,(%eax)
  4037f7:	8d 44 16 01          	lea    0x1(%esi,%edx,1),%eax
  4037fb:	eb 2d                	jmp    40382a <___mingw_opendir+0xba>
  4037fd:	8d 76 00             	lea    0x0(%esi),%esi
  403800:	8b 0a                	mov    (%edx),%ecx
  403802:	83 c2 04             	add    $0x4,%edx
  403805:	8d 81 ff fe fe fe    	lea    -0x1010101(%ecx),%eax
  40380b:	f7 d1                	not    %ecx
  40380d:	21 c8                	and    %ecx,%eax
  40380f:	25 80 80 80 80       	and    $0x80808080,%eax
  403814:	74 ea                	je     403800 <___mingw_opendir+0x90>
  403816:	a9 80 80 00 00       	test   $0x8080,%eax
  40381b:	0f 84 d7 00 00 00    	je     4038f8 <___mingw_opendir+0x188>
  403821:	89 c3                	mov    %eax,%ebx
  403823:	00 c3                	add    %al,%bl
  403825:	89 d0                	mov    %edx,%eax
  403827:	83 d8 03             	sbb    $0x3,%eax
  40382a:	ba 2a 00 00 00       	mov    $0x2a,%edx
  40382f:	89 f3                	mov    %esi,%ebx
  403831:	66 89 10             	mov    %dx,(%eax)
  403834:	8b 13                	mov    (%ebx),%edx
  403836:	83 c3 04             	add    $0x4,%ebx
  403839:	8d 82 ff fe fe fe    	lea    -0x1010101(%edx),%eax
  40383f:	f7 d2                	not    %edx
  403841:	21 d0                	and    %edx,%eax
  403843:	25 80 80 80 80       	and    $0x80808080,%eax
  403848:	74 ea                	je     403834 <___mingw_opendir+0xc4>
  40384a:	a9 80 80 00 00       	test   $0x8080,%eax
  40384f:	75 06                	jne    403857 <___mingw_opendir+0xe7>
  403851:	c1 e8 10             	shr    $0x10,%eax
  403854:	83 c3 02             	add    $0x2,%ebx
  403857:	89 c1                	mov    %eax,%ecx
  403859:	00 c1                	add    %al,%cl
  40385b:	83 db 03             	sbb    $0x3,%ebx
  40385e:	29 f3                	sub    %esi,%ebx
  403860:	8d 83 1c 01 00 00    	lea    0x11c(%ebx),%eax
  403866:	89 04 24             	mov    %eax,(%esp)
  403869:	e8 66 05 00 00       	call   403dd4 <_malloc>
  40386e:	89 c5                	mov    %eax,%ebp
  403870:	85 c0                	test   %eax,%eax
  403872:	0f 84 e7 00 00 00    	je     40395f <___mingw_opendir+0x1ef>
  403878:	8d 4b 01             	lea    0x1(%ebx),%ecx
  40387b:	8d 80 18 01 00 00    	lea    0x118(%eax),%eax
  403881:	83 f9 04             	cmp    $0x4,%ecx
  403884:	72 52                	jb     4038d8 <___mingw_opendir+0x168>
  403886:	8b 54 0c 18          	mov    0x18(%esp,%ecx,1),%edx
  40388a:	c1 eb 02             	shr    $0x2,%ebx
  40388d:	89 c7                	mov    %eax,%edi
  40388f:	89 54 08 fc          	mov    %edx,-0x4(%eax,%ecx,1)
  403893:	89 d9                	mov    %ebx,%ecx
  403895:	f3 a5                	rep movsl %ds:(%esi),%es:(%edi)
  403897:	89 ea                	mov    %ebp,%edx
  403899:	e8 22 fd ff ff       	call   4035c0 <.text>
  40389e:	89 85 10 01 00 00    	mov    %eax,0x110(%ebp)
  4038a4:	83 f8 ff             	cmp    $0xffffffff,%eax
  4038a7:	0f 84 a3 00 00 00    	je     403950 <___mingw_opendir+0x1e0>
  4038ad:	b8 10 01 00 00       	mov    $0x110,%eax
  4038b2:	c7 45 00 00 00 00 00 	movl   $0x0,0x0(%ebp)
  4038b9:	c7 85 14 01 00 00 00 	movl   $0x0,0x114(%ebp)
  4038c0:	00 00 00 
  4038c3:	66 89 45 04          	mov    %ax,0x4(%ebp)
  4038c7:	81 c4 2c 01 00 00    	add    $0x12c,%esp
  4038cd:	89 e8                	mov    %ebp,%eax
  4038cf:	5b                   	pop    %ebx
  4038d0:	5e                   	pop    %esi
  4038d1:	5f                   	pop    %edi
  4038d2:	5d                   	pop    %ebp
  4038d3:	c3                   	ret    
  4038d4:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  4038d8:	85 c9                	test   %ecx,%ecx
  4038da:	74 bb                	je     403897 <___mingw_opendir+0x127>
  4038dc:	0f b6 16             	movzbl (%esi),%edx
  4038df:	88 10                	mov    %dl,(%eax)
  4038e1:	f6 c1 02             	test   $0x2,%cl
  4038e4:	74 b1                	je     403897 <___mingw_opendir+0x127>
  4038e6:	0f b7 54 0e fe       	movzwl -0x2(%esi,%ecx,1),%edx
  4038eb:	66 89 54 08 fe       	mov    %dx,-0x2(%eax,%ecx,1)
  4038f0:	eb a5                	jmp    403897 <___mingw_opendir+0x127>
  4038f2:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  4038f8:	c1 e8 10             	shr    $0x10,%eax
  4038fb:	83 c2 02             	add    $0x2,%edx
  4038fe:	e9 1e ff ff ff       	jmp    403821 <___mingw_opendir+0xb1>
  403903:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  403907:	90                   	nop
  403908:	c1 e8 10             	shr    $0x10,%eax
  40390b:	83 c2 02             	add    $0x2,%edx
  40390e:	e9 c1 fe ff ff       	jmp    4037d4 <___mingw_opendir+0x64>
  403913:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  403917:	90                   	nop
  403918:	e8 ff 04 00 00       	call   403e1c <__errno>
  40391d:	31 ed                	xor    %ebp,%ebp
  40391f:	c7 00 02 00 00 00    	movl   $0x2,(%eax)
  403925:	81 c4 2c 01 00 00    	add    $0x12c,%esp
  40392b:	89 e8                	mov    %ebp,%eax
  40392d:	5b                   	pop    %ebx
  40392e:	5e                   	pop    %esi
  40392f:	5f                   	pop    %edi
  403930:	5d                   	pop    %ebp
  403931:	c3                   	ret    
  403932:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  403938:	e8 df 04 00 00       	call   403e1c <__errno>
  40393d:	31 ed                	xor    %ebp,%ebp
  40393f:	c7 00 16 00 00 00    	movl   $0x16,(%eax)
  403945:	eb 80                	jmp    4038c7 <___mingw_opendir+0x157>
  403947:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  40394e:	66 90                	xchg   %ax,%ax
  403950:	89 2c 24             	mov    %ebp,(%esp)
  403953:	31 ed                	xor    %ebp,%ebp
  403955:	e8 16 e7 ff ff       	call   402070 <___mingw_aligned_free>
  40395a:	e9 68 ff ff ff       	jmp    4038c7 <___mingw_opendir+0x157>
  40395f:	e8 b8 04 00 00       	call   403e1c <__errno>
  403964:	c7 00 0c 00 00 00    	movl   $0xc,(%eax)
  40396a:	e9 58 ff ff ff       	jmp    4038c7 <___mingw_opendir+0x157>
  40396f:	90                   	nop

00403970 <___mingw_readdir>:
  403970:	53                   	push   %ebx
  403971:	83 ec 08             	sub    $0x8,%esp
  403974:	8b 44 24 10          	mov    0x10(%esp),%eax
  403978:	85 c0                	test   %eax,%eax
  40397a:	74 34                	je     4039b0 <___mingw_readdir+0x40>
  40397c:	8b 90 14 01 00 00    	mov    0x114(%eax),%edx
  403982:	89 c3                	mov    %eax,%ebx
  403984:	8d 4a 01             	lea    0x1(%edx),%ecx
  403987:	89 88 14 01 00 00    	mov    %ecx,0x114(%eax)
  40398d:	85 d2                	test   %edx,%edx
  40398f:	7e 16                	jle    4039a7 <___mingw_readdir+0x37>
  403991:	8b 80 10 01 00 00    	mov    0x110(%eax),%eax
  403997:	89 da                	mov    %ebx,%edx
  403999:	e8 12 fd ff ff       	call   4036b0 <.text+0xf0>
  40399e:	83 f8 01             	cmp    $0x1,%eax
  4039a1:	19 c0                	sbb    %eax,%eax
  4039a3:	f7 d0                	not    %eax
  4039a5:	21 c3                	and    %eax,%ebx
  4039a7:	83 c4 08             	add    $0x8,%esp
  4039aa:	89 d8                	mov    %ebx,%eax
  4039ac:	5b                   	pop    %ebx
  4039ad:	c3                   	ret    
  4039ae:	66 90                	xchg   %ax,%ax
  4039b0:	e8 67 04 00 00       	call   403e1c <__errno>
  4039b5:	31 db                	xor    %ebx,%ebx
  4039b7:	c7 00 09 00 00 00    	movl   $0x9,(%eax)
  4039bd:	eb e8                	jmp    4039a7 <___mingw_readdir+0x37>
  4039bf:	90                   	nop

004039c0 <___mingw_closedir>:
  4039c0:	53                   	push   %ebx
  4039c1:	83 ec 18             	sub    $0x18,%esp
  4039c4:	8b 5c 24 20          	mov    0x20(%esp),%ebx
  4039c8:	85 db                	test   %ebx,%ebx
  4039ca:	74 24                	je     4039f0 <___mingw_closedir+0x30>
  4039cc:	8b 83 10 01 00 00    	mov    0x110(%ebx),%eax
  4039d2:	89 04 24             	mov    %eax,(%esp)
  4039d5:	e8 da 04 00 00       	call   403eb4 <_FindClose@4>
  4039da:	83 ec 04             	sub    $0x4,%esp
  4039dd:	85 c0                	test   %eax,%eax
  4039df:	74 0f                	je     4039f0 <___mingw_closedir+0x30>
  4039e1:	89 1c 24             	mov    %ebx,(%esp)
  4039e4:	e8 87 e6 ff ff       	call   402070 <___mingw_aligned_free>
  4039e9:	31 c0                	xor    %eax,%eax
  4039eb:	83 c4 18             	add    $0x18,%esp
  4039ee:	5b                   	pop    %ebx
  4039ef:	c3                   	ret    
  4039f0:	e8 27 04 00 00       	call   403e1c <__errno>
  4039f5:	c7 00 09 00 00 00    	movl   $0x9,(%eax)
  4039fb:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  403a00:	eb e9                	jmp    4039eb <___mingw_closedir+0x2b>
  403a02:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  403a09:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi

00403a10 <___mingw_rewinddir>:
  403a10:	53                   	push   %ebx
  403a11:	83 ec 18             	sub    $0x18,%esp
  403a14:	8b 5c 24 20          	mov    0x20(%esp),%ebx
  403a18:	85 db                	test   %ebx,%ebx
  403a1a:	74 15                	je     403a31 <___mingw_rewinddir+0x21>
  403a1c:	8b 83 10 01 00 00    	mov    0x110(%ebx),%eax
  403a22:	89 04 24             	mov    %eax,(%esp)
  403a25:	e8 8a 04 00 00       	call   403eb4 <_FindClose@4>
  403a2a:	83 ec 04             	sub    $0x4,%esp
  403a2d:	85 c0                	test   %eax,%eax
  403a2f:	75 17                	jne    403a48 <___mingw_rewinddir+0x38>
  403a31:	e8 e6 03 00 00       	call   403e1c <__errno>
  403a36:	c7 00 09 00 00 00    	movl   $0x9,(%eax)
  403a3c:	83 c4 18             	add    $0x18,%esp
  403a3f:	5b                   	pop    %ebx
  403a40:	c3                   	ret    
  403a41:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  403a48:	8d 83 18 01 00 00    	lea    0x118(%ebx),%eax
  403a4e:	89 da                	mov    %ebx,%edx
  403a50:	e8 6b fb ff ff       	call   4035c0 <.text>
  403a55:	89 83 10 01 00 00    	mov    %eax,0x110(%ebx)
  403a5b:	83 f8 ff             	cmp    $0xffffffff,%eax
  403a5e:	74 dc                	je     403a3c <___mingw_rewinddir+0x2c>
  403a60:	c7 83 14 01 00 00 00 	movl   $0x0,0x114(%ebx)
  403a67:	00 00 00 
  403a6a:	83 c4 18             	add    $0x18,%esp
  403a6d:	5b                   	pop    %ebx
  403a6e:	c3                   	ret    
  403a6f:	90                   	nop

00403a70 <___mingw_telldir>:
  403a70:	83 ec 0c             	sub    $0xc,%esp
  403a73:	8b 44 24 10          	mov    0x10(%esp),%eax
  403a77:	85 c0                	test   %eax,%eax
  403a79:	74 0a                	je     403a85 <___mingw_telldir+0x15>
  403a7b:	8b 80 14 01 00 00    	mov    0x114(%eax),%eax
  403a81:	83 c4 0c             	add    $0xc,%esp
  403a84:	c3                   	ret    
  403a85:	e8 92 03 00 00       	call   403e1c <__errno>
  403a8a:	c7 00 09 00 00 00    	movl   $0x9,(%eax)
  403a90:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  403a95:	eb ea                	jmp    403a81 <___mingw_telldir+0x11>
  403a97:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  403a9e:	66 90                	xchg   %ax,%ax

00403aa0 <___mingw_seekdir>:
  403aa0:	56                   	push   %esi
  403aa1:	53                   	push   %ebx
  403aa2:	83 ec 14             	sub    $0x14,%esp
  403aa5:	8b 74 24 24          	mov    0x24(%esp),%esi
  403aa9:	8b 5c 24 20          	mov    0x20(%esp),%ebx
  403aad:	85 f6                	test   %esi,%esi
  403aaf:	78 4f                	js     403b00 <___mingw_seekdir+0x60>
  403ab1:	89 1c 24             	mov    %ebx,(%esp)
  403ab4:	e8 57 ff ff ff       	call   403a10 <___mingw_rewinddir>
  403ab9:	85 f6                	test   %esi,%esi
  403abb:	74 37                	je     403af4 <___mingw_seekdir+0x54>
  403abd:	83 bb 10 01 00 00 ff 	cmpl   $0xffffffff,0x110(%ebx)
  403ac4:	75 1b                	jne    403ae1 <___mingw_seekdir+0x41>
  403ac6:	eb 2c                	jmp    403af4 <___mingw_seekdir+0x54>
  403ac8:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  403acf:	90                   	nop
  403ad0:	8b 83 10 01 00 00    	mov    0x110(%ebx),%eax
  403ad6:	89 da                	mov    %ebx,%edx
  403ad8:	e8 d3 fb ff ff       	call   4036b0 <.text+0xf0>
  403add:	85 c0                	test   %eax,%eax
  403adf:	74 13                	je     403af4 <___mingw_seekdir+0x54>
  403ae1:	8b 83 14 01 00 00    	mov    0x114(%ebx),%eax
  403ae7:	83 c0 01             	add    $0x1,%eax
  403aea:	89 83 14 01 00 00    	mov    %eax,0x114(%ebx)
  403af0:	39 f0                	cmp    %esi,%eax
  403af2:	7c dc                	jl     403ad0 <___mingw_seekdir+0x30>
  403af4:	83 c4 14             	add    $0x14,%esp
  403af7:	5b                   	pop    %ebx
  403af8:	5e                   	pop    %esi
  403af9:	c3                   	ret    
  403afa:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  403b00:	e8 17 03 00 00       	call   403e1c <__errno>
  403b05:	c7 00 16 00 00 00    	movl   $0x16,(%eax)
  403b0b:	83 c4 14             	add    $0x14,%esp
  403b0e:	5b                   	pop    %ebx
  403b0f:	5e                   	pop    %esi
  403b10:	c3                   	ret    
  403b11:	90                   	nop
  403b12:	90                   	nop
  403b13:	90                   	nop
  403b14:	90                   	nop
  403b15:	90                   	nop
  403b16:	90                   	nop
  403b17:	90                   	nop
  403b18:	90                   	nop
  403b19:	90                   	nop
  403b1a:	90                   	nop
  403b1b:	90                   	nop
  403b1c:	90                   	nop
  403b1d:	90                   	nop
  403b1e:	90                   	nop
  403b1f:	90                   	nop

00403b20 <___mingw_memalign_base>:
  403b20:	55                   	push   %ebp
  403b21:	57                   	push   %edi
  403b22:	56                   	push   %esi
  403b23:	53                   	push   %ebx
  403b24:	83 ec 08             	sub    $0x8,%esp
  403b27:	8b 44 24 1c          	mov    0x1c(%esp),%eax
  403b2b:	85 c0                	test   %eax,%eax
  403b2d:	0f 84 83 00 00 00    	je     403bb6 <___mingw_memalign_base+0x96>
  403b33:	8b 35 6c 70 40 00    	mov    0x40706c,%esi
  403b39:	85 f6                	test   %esi,%esi
  403b3b:	74 79                	je     403bb6 <___mingw_memalign_base+0x96>
  403b3d:	8d 56 08             	lea    0x8(%esi),%edx
  403b40:	39 c2                	cmp    %eax,%edx
  403b42:	77 72                	ja     403bb6 <___mingw_memalign_base+0x96>
  403b44:	8d 50 fc             	lea    -0x4(%eax),%edx
  403b47:	8b 7c 24 20          	mov    0x20(%esp),%edi
  403b4b:	83 e2 fc             	and    $0xfffffffc,%edx
  403b4e:	8b 12                	mov    (%edx),%edx
  403b50:	89 d3                	mov    %edx,%ebx
  403b52:	89 d1                	mov    %edx,%ecx
  403b54:	83 e3 03             	and    $0x3,%ebx
  403b57:	83 e1 fc             	and    $0xfffffffc,%ecx
  403b5a:	89 5f 04             	mov    %ebx,0x4(%edi)
  403b5d:	89 0f                	mov    %ecx,(%edi)
  403b5f:	39 ce                	cmp    %ecx,%esi
  403b61:	77 53                	ja     403bb6 <___mingw_memalign_base+0x96>
  403b63:	8d 70 f8             	lea    -0x8(%eax),%esi
  403b66:	39 f1                	cmp    %esi,%ecx
  403b68:	77 4c                	ja     403bb6 <___mingw_memalign_base+0x96>
  403b6a:	89 4c 24 04          	mov    %ecx,0x4(%esp)
  403b6e:	f6 c2 01             	test   $0x1,%dl
  403b71:	74 4d                	je     403bc0 <___mingw_memalign_base+0xa0>
  403b73:	8b 39                	mov    (%ecx),%edi
  403b75:	89 fd                	mov    %edi,%ebp
  403b77:	8d 77 07             	lea    0x7(%edi),%esi
  403b7a:	f7 dd                	neg    %ebp
  403b7c:	89 2c 24             	mov    %ebp,(%esp)
  403b7f:	8b 6c 24 20          	mov    0x20(%esp),%ebp
  403b83:	89 7d 08             	mov    %edi,0x8(%ebp)
  403b86:	83 e2 02             	and    $0x2,%edx
  403b89:	74 0b                	je     403b96 <___mingw_memalign_base+0x76>
  403b8b:	8d 53 01             	lea    0x1(%ebx),%edx
  403b8e:	c1 ea 02             	shr    $0x2,%edx
  403b91:	8b 14 91             	mov    (%ecx,%edx,4),%edx
  403b94:	01 d1                	add    %edx,%ecx
  403b96:	8b 6c 24 20          	mov    0x20(%esp),%ebp
  403b9a:	89 55 0c             	mov    %edx,0xc(%ebp)
  403b9d:	83 fb 03             	cmp    $0x3,%ebx
  403ba0:	75 03                	jne    403ba5 <___mingw_memalign_base+0x85>
  403ba2:	8d 77 0b             	lea    0xb(%edi),%esi
  403ba5:	8b 2c 24             	mov    (%esp),%ebp
  403ba8:	01 f1                	add    %esi,%ecx
  403baa:	21 cd                	and    %ecx,%ebp
  403bac:	29 d5                	sub    %edx,%ebp
  403bae:	39 e8                	cmp    %ebp,%eax
  403bb0:	75 04                	jne    403bb6 <___mingw_memalign_base+0x96>
  403bb2:	8b 44 24 04          	mov    0x4(%esp),%eax
  403bb6:	83 c4 08             	add    $0x8,%esp
  403bb9:	5b                   	pop    %ebx
  403bba:	5e                   	pop    %esi
  403bbb:	5f                   	pop    %edi
  403bbc:	5d                   	pop    %ebp
  403bbd:	c3                   	ret    
  403bbe:	66 90                	xchg   %ax,%ax
  403bc0:	c7 04 24 f8 ff ff ff 	movl   $0xfffffff8,(%esp)
  403bc7:	be 0f 00 00 00       	mov    $0xf,%esi
  403bcc:	bf 08 00 00 00       	mov    $0x8,%edi
  403bd1:	eb ac                	jmp    403b7f <___mingw_memalign_base+0x5f>
  403bd3:	90                   	nop
  403bd4:	90                   	nop
  403bd5:	90                   	nop
  403bd6:	90                   	nop
  403bd7:	90                   	nop
  403bd8:	90                   	nop
  403bd9:	90                   	nop
  403bda:	90                   	nop
  403bdb:	90                   	nop
  403bdc:	90                   	nop
  403bdd:	90                   	nop
  403bde:	90                   	nop
  403bdf:	90                   	nop

00403be0 <___mingw_realloc>:
  403be0:	57                   	push   %edi
  403be1:	56                   	push   %esi
  403be2:	53                   	push   %ebx
  403be3:	83 ec 20             	sub    $0x20,%esp
  403be6:	8b 5c 24 30          	mov    0x30(%esp),%ebx
  403bea:	8b 74 24 34          	mov    0x34(%esp),%esi
  403bee:	85 db                	test   %ebx,%ebx
  403bf0:	74 3a                	je     403c2c <___mingw_realloc+0x4c>
  403bf2:	8d 7c 24 10          	lea    0x10(%esp),%edi
  403bf6:	89 1c 24             	mov    %ebx,(%esp)
  403bf9:	89 7c 24 04          	mov    %edi,0x4(%esp)
  403bfd:	e8 1e ff ff ff       	call   403b20 <___mingw_memalign_base>
  403c02:	39 c3                	cmp    %eax,%ebx
  403c04:	74 26                	je     403c2c <___mingw_realloc+0x4c>
  403c06:	85 f6                	test   %esi,%esi
  403c08:	74 1e                	je     403c28 <___mingw_realloc+0x48>
  403c0a:	39 74 24 1c          	cmp    %esi,0x1c(%esp)
  403c0e:	72 30                	jb     403c40 <___mingw_realloc+0x60>
  403c10:	e8 07 02 00 00       	call   403e1c <__errno>
  403c15:	c7 00 16 00 00 00    	movl   $0x16,(%eax)
  403c1b:	83 c4 20             	add    $0x20,%esp
  403c1e:	31 c0                	xor    %eax,%eax
  403c20:	5b                   	pop    %ebx
  403c21:	5e                   	pop    %esi
  403c22:	5f                   	pop    %edi
  403c23:	c3                   	ret    
  403c24:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  403c28:	8b 5c 24 10          	mov    0x10(%esp),%ebx
  403c2c:	89 74 24 04          	mov    %esi,0x4(%esp)
  403c30:	89 1c 24             	mov    %ebx,(%esp)
  403c33:	ff 15 10 82 40 00    	call   *0x408210
  403c39:	83 c4 20             	add    $0x20,%esp
  403c3c:	5b                   	pop    %ebx
  403c3d:	5e                   	pop    %esi
  403c3e:	5f                   	pop    %edi
  403c3f:	c3                   	ret    
  403c40:	89 74 24 08          	mov    %esi,0x8(%esp)
  403c44:	89 7c 24 04          	mov    %edi,0x4(%esp)
  403c48:	89 1c 24             	mov    %ebx,(%esp)
  403c4b:	e8 10 00 00 00       	call   403c60 <___mingw_memalign_realloc>
  403c50:	83 c4 20             	add    $0x20,%esp
  403c53:	5b                   	pop    %ebx
  403c54:	5e                   	pop    %esi
  403c55:	5f                   	pop    %edi
  403c56:	c3                   	ret    
  403c57:	90                   	nop
  403c58:	90                   	nop
  403c59:	90                   	nop
  403c5a:	90                   	nop
  403c5b:	90                   	nop
  403c5c:	90                   	nop
  403c5d:	90                   	nop
  403c5e:	90                   	nop
  403c5f:	90                   	nop

00403c60 <___mingw_memalign_realloc>:
  403c60:	55                   	push   %ebp
  403c61:	57                   	push   %edi
  403c62:	56                   	push   %esi
  403c63:	53                   	push   %ebx
  403c64:	83 ec 1c             	sub    $0x1c,%esp
  403c67:	8b 74 24 34          	mov    0x34(%esp),%esi
  403c6b:	8b 06                	mov    (%esi),%eax
  403c6d:	89 04 24             	mov    %eax,(%esp)
  403c70:	e8 8f 01 00 00       	call   403e04 <__msize>
  403c75:	8b 56 08             	mov    0x8(%esi),%edx
  403c78:	89 c7                	mov    %eax,%edi
  403c7a:	8b 46 04             	mov    0x4(%esi),%eax
  403c7d:	8d 5a 07             	lea    0x7(%edx),%ebx
  403c80:	83 e0 03             	and    $0x3,%eax
  403c83:	83 f8 03             	cmp    $0x3,%eax
  403c86:	75 03                	jne    403c8b <___mingw_memalign_realloc+0x2b>
  403c88:	8d 5a 0b             	lea    0xb(%edx),%ebx
  403c8b:	8b 44 24 38          	mov    0x38(%esp),%eax
  403c8f:	01 d8                	add    %ebx,%eax
  403c91:	89 44 24 04          	mov    %eax,0x4(%esp)
  403c95:	8b 06                	mov    (%esi),%eax
  403c97:	89 04 24             	mov    %eax,(%esp)
  403c9a:	ff 15 10 82 40 00    	call   *0x408210
  403ca0:	8b 16                	mov    (%esi),%edx
  403ca2:	39 c2                	cmp    %eax,%edx
  403ca4:	0f 84 86 00 00 00    	je     403d30 <___mingw_memalign_realloc+0xd0>
  403caa:	31 ed                	xor    %ebp,%ebp
  403cac:	85 c0                	test   %eax,%eax
  403cae:	74 59                	je     403d09 <___mingw_memalign_realloc+0xa9>
  403cb0:	8b 4c 24 30          	mov    0x30(%esp),%ecx
  403cb4:	8b 2d 6c 70 40 00    	mov    0x40706c,%ebp
  403cba:	29 d1                	sub    %edx,%ecx
  403cbc:	85 ed                	test   %ebp,%ebp
  403cbe:	75 58                	jne    403d18 <___mingw_memalign_realloc+0xb8>
  403cc0:	a3 6c 70 40 00       	mov    %eax,0x40706c
  403cc5:	8b 6e 04             	mov    0x4(%esi),%ebp
  403cc8:	03 5e 0c             	add    0xc(%esi),%ebx
  403ccb:	01 c3                	add    %eax,%ebx
  403ccd:	09 c5                	or     %eax,%ebp
  403ccf:	01 c8                	add    %ecx,%eax
  403cd1:	89 2e                	mov    %ebp,(%esi)
  403cd3:	8b 6e 08             	mov    0x8(%esi),%ebp
  403cd6:	f7 dd                	neg    %ebp
  403cd8:	21 eb                	and    %ebp,%ebx
  403cda:	2b 5e 0c             	sub    0xc(%esi),%ebx
  403cdd:	89 dd                	mov    %ebx,%ebp
  403cdf:	39 c3                	cmp    %eax,%ebx
  403ce1:	74 1c                	je     403cff <___mingw_memalign_realloc+0x9f>
  403ce3:	2b 54 24 30          	sub    0x30(%esp),%edx
  403ce7:	01 d7                	add    %edx,%edi
  403ce9:	3b 7c 24 38          	cmp    0x38(%esp),%edi
  403ced:	77 31                	ja     403d20 <___mingw_memalign_realloc+0xc0>
  403cef:	89 7c 24 08          	mov    %edi,0x8(%esp)
  403cf3:	89 44 24 04          	mov    %eax,0x4(%esp)
  403cf7:	89 1c 24             	mov    %ebx,(%esp)
  403cfa:	e8 bd 00 00 00       	call   403dbc <_memmove>
  403cff:	8b 06                	mov    (%esi),%eax
  403d01:	83 eb 04             	sub    $0x4,%ebx
  403d04:	83 e3 fc             	and    $0xfffffffc,%ebx
  403d07:	89 03                	mov    %eax,(%ebx)
  403d09:	83 c4 1c             	add    $0x1c,%esp
  403d0c:	89 e8                	mov    %ebp,%eax
  403d0e:	5b                   	pop    %ebx
  403d0f:	5e                   	pop    %esi
  403d10:	5f                   	pop    %edi
  403d11:	5d                   	pop    %ebp
  403d12:	c3                   	ret    
  403d13:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  403d17:	90                   	nop
  403d18:	39 c5                	cmp    %eax,%ebp
  403d1a:	76 a9                	jbe    403cc5 <___mingw_memalign_realloc+0x65>
  403d1c:	eb a2                	jmp    403cc0 <___mingw_memalign_realloc+0x60>
  403d1e:	66 90                	xchg   %ax,%ax
  403d20:	8b 7c 24 38          	mov    0x38(%esp),%edi
  403d24:	eb c9                	jmp    403cef <___mingw_memalign_realloc+0x8f>
  403d26:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  403d2d:	8d 76 00             	lea    0x0(%esi),%esi
  403d30:	8b 6c 24 30          	mov    0x30(%esp),%ebp
  403d34:	83 c4 1c             	add    $0x1c,%esp
  403d37:	5b                   	pop    %ebx
  403d38:	5e                   	pop    %esi
  403d39:	89 e8                	mov    %ebp,%eax
  403d3b:	5f                   	pop    %edi
  403d3c:	5d                   	pop    %ebp
  403d3d:	c3                   	ret    
  403d3e:	90                   	nop
  403d3f:	90                   	nop

00403d40 <___chkstk_ms>:
  403d40:	51                   	push   %ecx
  403d41:	50                   	push   %eax
  403d42:	3d 00 10 00 00       	cmp    $0x1000,%eax
  403d47:	8d 4c 24 0c          	lea    0xc(%esp),%ecx
  403d4b:	72 15                	jb     403d62 <___chkstk_ms+0x22>
  403d4d:	81 e9 00 10 00 00    	sub    $0x1000,%ecx
  403d53:	83 09 00             	orl    $0x0,(%ecx)
  403d56:	2d 00 10 00 00       	sub    $0x1000,%eax
  403d5b:	3d 00 10 00 00       	cmp    $0x1000,%eax
  403d60:	77 eb                	ja     403d4d <___chkstk_ms+0xd>
  403d62:	29 c1                	sub    %eax,%ecx
  403d64:	83 09 00             	orl    $0x0,(%ecx)
  403d67:	58                   	pop    %eax
  403d68:	59                   	pop    %ecx
  403d69:	c3                   	ret    
  403d6a:	90                   	nop
  403d6b:	90                   	nop

00403d6c <_stricoll>:
  403d6c:	ff 25 84 81 40 00    	jmp    *0x408184
  403d72:	90                   	nop
  403d73:	90                   	nop

00403d74 <_strdup>:
  403d74:	ff 25 80 81 40 00    	jmp    *0x408180
  403d7a:	90                   	nop
  403d7b:	90                   	nop

00403d7c <_wcstombs>:
  403d7c:	ff 25 08 82 40 00    	jmp    *0x408208
  403d82:	90                   	nop
  403d83:	90                   	nop

00403d84 <_vfprintf>:
  403d84:	ff 25 04 82 40 00    	jmp    *0x408204
  403d8a:	90                   	nop
  403d8b:	90                   	nop

00403d8c <_tolower>:
  403d8c:	ff 25 00 82 40 00    	jmp    *0x408200
  403d92:	90                   	nop
  403d93:	90                   	nop

00403d94 <_strlen>:
  403d94:	ff 25 fc 81 40 00    	jmp    *0x4081fc
  403d9a:	90                   	nop
  403d9b:	90                   	nop

00403d9c <_strcoll>:
  403d9c:	ff 25 f8 81 40 00    	jmp    *0x4081f8
  403da2:	90                   	nop
  403da3:	90                   	nop

00403da4 <_signal>:
  403da4:	ff 25 f4 81 40 00    	jmp    *0x4081f4
  403daa:	90                   	nop
  403dab:	90                   	nop

00403dac <_setlocale>:
  403dac:	ff 25 f0 81 40 00    	jmp    *0x4081f0
  403db2:	90                   	nop
  403db3:	90                   	nop

00403db4 <_printf>:
  403db4:	ff 25 ec 81 40 00    	jmp    *0x4081ec
  403dba:	90                   	nop
  403dbb:	90                   	nop

00403dbc <_memmove>:
  403dbc:	ff 25 e8 81 40 00    	jmp    *0x4081e8
  403dc2:	90                   	nop
  403dc3:	90                   	nop

00403dc4 <_memcpy>:
  403dc4:	ff 25 e4 81 40 00    	jmp    *0x4081e4
  403dca:	90                   	nop
  403dcb:	90                   	nop

00403dcc <_mbstowcs>:
  403dcc:	ff 25 e0 81 40 00    	jmp    *0x4081e0
  403dd2:	90                   	nop
  403dd3:	90                   	nop

00403dd4 <_malloc>:
  403dd4:	ff 25 dc 81 40 00    	jmp    *0x4081dc
  403dda:	90                   	nop
  403ddb:	90                   	nop

00403ddc <_fwrite>:
  403ddc:	ff 25 d8 81 40 00    	jmp    *0x4081d8
  403de2:	90                   	nop
  403de3:	90                   	nop

00403de4 <_calloc>:
  403de4:	ff 25 d4 81 40 00    	jmp    *0x4081d4
  403dea:	90                   	nop
  403deb:	90                   	nop

00403dec <_atoi>:
  403dec:	ff 25 d0 81 40 00    	jmp    *0x4081d0
  403df2:	90                   	nop
  403df3:	90                   	nop

00403df4 <_abort>:
  403df4:	ff 25 c8 81 40 00    	jmp    *0x4081c8
  403dfa:	90                   	nop
  403dfb:	90                   	nop

00403dfc <__setmode>:
  403dfc:	ff 25 c4 81 40 00    	jmp    *0x4081c4
  403e02:	90                   	nop
  403e03:	90                   	nop

00403e04 <__msize>:
  403e04:	ff 25 b8 81 40 00    	jmp    *0x4081b8
  403e0a:	90                   	nop
  403e0b:	90                   	nop

00403e0c <__isctype>:
  403e0c:	ff 25 b4 81 40 00    	jmp    *0x4081b4
  403e12:	90                   	nop
  403e13:	90                   	nop

00403e14 <__fullpath>:
  403e14:	ff 25 ac 81 40 00    	jmp    *0x4081ac
  403e1a:	90                   	nop
  403e1b:	90                   	nop

00403e1c <__errno>:
  403e1c:	ff 25 a4 81 40 00    	jmp    *0x4081a4
  403e22:	90                   	nop
  403e23:	90                   	nop

00403e24 <__cexit>:
  403e24:	ff 25 a0 81 40 00    	jmp    *0x4081a0
  403e2a:	90                   	nop
  403e2b:	90                   	nop

00403e2c <___p__fmode>:
  403e2c:	ff 25 98 81 40 00    	jmp    *0x408198
  403e32:	90                   	nop
  403e33:	90                   	nop

00403e34 <___p__environ>:
  403e34:	ff 25 94 81 40 00    	jmp    *0x408194
  403e3a:	90                   	nop
  403e3b:	90                   	nop

00403e3c <___getmainargs>:
  403e3c:	ff 25 8c 81 40 00    	jmp    *0x40818c
  403e42:	90                   	nop
  403e43:	90                   	nop

00403e44 <_VirtualQuery@12>:
  403e44:	ff 25 78 81 40 00    	jmp    *0x408178
  403e4a:	90                   	nop
  403e4b:	90                   	nop

00403e4c <_VirtualProtect@16>:
  403e4c:	ff 25 74 81 40 00    	jmp    *0x408174
  403e52:	90                   	nop
  403e53:	90                   	nop

00403e54 <_TlsGetValue@4>:
  403e54:	ff 25 70 81 40 00    	jmp    *0x408170
  403e5a:	90                   	nop
  403e5b:	90                   	nop

00403e5c <_SetUnhandledExceptionFilter@4>:
  403e5c:	ff 25 6c 81 40 00    	jmp    *0x40816c
  403e62:	90                   	nop
  403e63:	90                   	nop

00403e64 <_LoadLibraryA@4>:
  403e64:	ff 25 68 81 40 00    	jmp    *0x408168
  403e6a:	90                   	nop
  403e6b:	90                   	nop

00403e6c <_LeaveCriticalSection@4>:
  403e6c:	ff 25 64 81 40 00    	jmp    *0x408164
  403e72:	90                   	nop
  403e73:	90                   	nop

00403e74 <_InitializeCriticalSection@4>:
  403e74:	ff 25 60 81 40 00    	jmp    *0x408160
  403e7a:	90                   	nop
  403e7b:	90                   	nop

00403e7c <_GetProcAddress@8>:
  403e7c:	ff 25 5c 81 40 00    	jmp    *0x40815c
  403e82:	90                   	nop
  403e83:	90                   	nop

00403e84 <_GetModuleHandleA@4>:
  403e84:	ff 25 58 81 40 00    	jmp    *0x408158
  403e8a:	90                   	nop
  403e8b:	90                   	nop

00403e8c <_GetLastError@0>:
  403e8c:	ff 25 54 81 40 00    	jmp    *0x408154
  403e92:	90                   	nop
  403e93:	90                   	nop

00403e94 <_GetCommandLineA@0>:
  403e94:	ff 25 50 81 40 00    	jmp    *0x408150
  403e9a:	90                   	nop
  403e9b:	90                   	nop

00403e9c <_FreeLibrary@4>:
  403e9c:	ff 25 4c 81 40 00    	jmp    *0x40814c
  403ea2:	90                   	nop
  403ea3:	90                   	nop

00403ea4 <_FindNextFileA@8>:
  403ea4:	ff 25 48 81 40 00    	jmp    *0x408148
  403eaa:	90                   	nop
  403eab:	90                   	nop

00403eac <_FindFirstFileA@8>:
  403eac:	ff 25 44 81 40 00    	jmp    *0x408144
  403eb2:	90                   	nop
  403eb3:	90                   	nop

00403eb4 <_FindClose@4>:
  403eb4:	ff 25 40 81 40 00    	jmp    *0x408140
  403eba:	90                   	nop
  403ebb:	90                   	nop

00403ebc <_ExitProcess@4>:
  403ebc:	ff 25 3c 81 40 00    	jmp    *0x40813c
  403ec2:	90                   	nop
  403ec3:	90                   	nop

00403ec4 <_EnterCriticalSection@4>:
  403ec4:	ff 25 38 81 40 00    	jmp    *0x408138
  403eca:	90                   	nop
  403ecb:	90                   	nop

00403ecc <_DeleteCriticalSection@4>:
  403ecc:	ff 25 34 81 40 00    	jmp    *0x408134
  403ed2:	90                   	nop
  403ed3:	90                   	nop

00403ed4 <.text>:
  403ed4:	66 90                	xchg   %ax,%ax
  403ed6:	66 90                	xchg   %ax,%ax
  403ed8:	66 90                	xchg   %ax,%ax
  403eda:	66 90                	xchg   %ax,%ax
  403edc:	66 90                	xchg   %ax,%ax
  403ede:	66 90                	xchg   %ax,%ax

00403ee0 <_main>:

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

int main(int argc, char *argv[])
{
  403ee0:	55                   	push   %ebp
  403ee1:	89 e5                	mov    %esp,%ebp
  403ee3:	83 e4 f0             	and    $0xfffffff0,%esp
  403ee6:	83 ec 10             	sub    $0x10,%esp
  403ee9:	e8 72 da ff ff       	call   401960 <___main>
    int a;

    /* Get the value from somewhere GCC can't optimize */
    a = atoi(argv[1]);
  403eee:	8b 45 0c             	mov    0xc(%ebp),%eax
  403ef1:	8b 40 04             	mov    0x4(%eax),%eax
  403ef4:	89 04 24             	mov    %eax,(%esp)
  403ef7:	e8 f0 fe ff ff       	call   403dec <_atoi>

    if (likely(a == 2))
        // if (likely(a == 2))
        a++;
    else
        a--;
  403efc:	8d 50 ff             	lea    -0x1(%eax),%edx
    if (likely(a == 2))
  403eff:	83 f8 02             	cmp    $0x2,%eax
  403f02:	75 05                	jne    403f09 <_main+0x29>
  403f04:	ba 03 00 00 00       	mov    $0x3,%edx

    printf("%d\n", a);
  403f09:	89 54 24 04          	mov    %edx,0x4(%esp)
  403f0d:	c7 04 24 44 50 40 00 	movl   $0x405044,(%esp)
  403f14:	e8 9b fe ff ff       	call   403db4 <_printf>

    return 0;
  403f19:	31 c0                	xor    %eax,%eax
  403f1b:	c9                   	leave  
  403f1c:	c3                   	ret    
  403f1d:	90                   	nop
  403f1e:	90                   	nop
  403f1f:	90                   	nop

00403f20 <_register_frame_ctor>:
  403f20:	e9 0b d4 ff ff       	jmp    401330 <___gcc_register_frame>
  403f25:	90                   	nop
  403f26:	90                   	nop
  403f27:	90                   	nop
  403f28:	90                   	nop
  403f29:	90                   	nop
  403f2a:	90                   	nop
  403f2b:	90                   	nop
  403f2c:	90                   	nop
  403f2d:	90                   	nop
  403f2e:	90                   	nop
  403f2f:	90                   	nop

00403f30 <__CTOR_LIST__>:
  403f30:	ff                   	(bad)  
  403f31:	ff                   	(bad)  
  403f32:	ff                   	(bad)  
  403f33:	ff                   	.byte 0xff

00403f34 <.ctors.65535>:
  403f34:	20 3f                	and    %bh,(%edi)
  403f36:	40                   	inc    %eax
  403f37:	00 00                	add    %al,(%eax)
  403f39:	00 00                	add    %al,(%eax)
	...

00403f3c <__DTOR_LIST__>:
  403f3c:	ff                   	(bad)  
  403f3d:	ff                   	(bad)  
  403f3e:	ff                   	(bad)  
  403f3f:	ff 00                	incl   (%eax)
  403f41:	00 00                	add    %al,(%eax)
	...
