

;==================== DECLARE =======================
ExitProcess PROTO STDCALL:DWORD

writeNewUser PROTO :PTR BYTE,:PTR BYTE
updateFriendStatus PROTO :PTR BYTE, :PTR BYTE, :DWORD
deleteFriend PROTO :PTR BYTE, :PTR BYTE
ifSignIn PROTO  :PTR BYTE
ifFriends PROTO :PTR BYTE, :PTR BYTE 
ifPasswordRight PROTO  :PTR BYTE, :PTR BYTE
readAllFriends PROTO :PTR BYTE, :PTR BYTE
;====================  CONST  =======================
.const
BUFSIZE		EQU		104857600
BACKLOG		EQU		5

IDC_COUNT EQU 40002


CLIENT_SUCCESS			EQU		0
CLIENT_FAIL				EQU		1
CLIENT_SIGNUP			EQU		2
CLIENT_LOGIN			EQU		3
CLIENT_LOGOUT			EQU		4
CLIENT_ROOM_TALK		EQU		5
CLIENT_1TO1_TALK		EQU		6
CLIENT_FRIEND_APPLY		EQU		7
CLIENT_FRIEND_REPLY		EQU		8
CLIENT_FRIEND_DELETE	EQU		9

CLIENT_SUCCESS_ASCII			EQU		48 ; ASCII '0'
CLIENT_FAIL_ASCII				EQU		49 ; ASCII '1'
CLIENT_SIGNUP_ASCII				EQU		50 ; ASCII '2'
CLIENT_LOGIN_ASCII				EQU		51 ; ASCII '3'
CLIENT_LOGOUT_ASCII				EQU		52 ; ASCII '4'
CLIENT_ROOM_TALK_ASCII			EQU		53 ; ASCII '5'
CLIENT_1TO1_TALK_ASCII			EQU		54 ; ASCII '6'
CLIENT_FRIEND_APPLY_ASCII		EQU		55 ; ASCII '7'
CLIENT_FRIEND_REPLY_ASCII		EQU		56 ; ASCII '8'
CLIENT_FRIEND_DELETE_ASCII		EQU		57 ; ASCII '9'


SERVER_INVALID			EQU		-1
SERVER_FAIL				EQU		0
SERVER_SUCCESS			EQU		1
SERVER_ROOM_TALK		EQU		2
SERVER_1TO1_TALK		EQU		3
SERVER_FRIEND_APPLY		EQU		4
SERVER_FRIEND_LIST		EQU		5
SERVER_FRIEND_NOTIFY	EQU		6
SERVER_ROOM_MEMBERS		EQU		7
SERVER_JOIN_LEAVE		EQU		8

IS_FRIEND			EQU		0
FRIEND_ONLINE		EQU		1
FRIEND_OFFLINE		EQU		2
FRIEND_PADDING		EQU		3
FRIEND_APPLY_PASS	EQU		4
FRIEND_APPLY_REJ	EQU		5
FRIEND_DELETED		EQU		6

IS_FRIEND_ASCII			EQU		48 ; ASCII '0'
FRIEND_ONLINE_ASCII		EQU		49 ; ASCII '1'
FRIEND_OFFLINE_ASCII	EQU		50 ; ASCII '2'
FRIEND_PADDING_ASCII	EQU		51 ; ASCII '3'
FRIEND_APPLY_PASS_ASCII	EQU		52 ; ASCII '4'
FRIEND_APPLY_REJ_ASCII	EQU		53 ; ASCII '5'
FRIEND_DELETED_ASCII	EQU		54 ; ASCII '6'

;====================  DATA  =======================
.data

SEP  db " ", 0
SEP1 db ":", 0

MSG_FORMAT0			db "%d", 0
MSG_FORMAT1			db "%d %s", 0
MSG_FORMAT2			db "%s%s %d ", 0
MSG_FORMAT3			db "%d %s %s", 0
MSG_FORMAT4			db "%d %s %d", 0
MSG_FORMAT5			db "%s:%d", 0
MSG_FORMAT6			db "%d %s %[^", 0dh, "\n]", 0
MSG_FORMAT7			db "%s%s", 0
MSG_FORMAT8			db "%d %[^", 0dh, "]", 0
MSG_FORMAT9			db "%s: %s", 0ah, 0dh, 0

DEBUG_FORMAT1		db "message send to %s: %s", 0ah, 0dh, 0
DEBUG_FORMAT2		db "message recv from %s: %s", 0ah, 0dh, 0