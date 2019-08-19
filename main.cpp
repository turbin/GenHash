#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include <map>
#include <string>
#include <regex>


static const char* gpszTrText[][3] = {
	{"PRINT ANY" , "",""},
	{"VIEW APPOINTED" , "",""},
	{"TRACE NO:" , "",""},
	{"PRINT RECIEPT?" , "",""},
	{"SALE:" , "",""},
	{"AUTH COMP:" , "",""},
	{"AUTH:" , "",""},
	{"REFUND:" , "",""},
	{"VOID:" , "",""},
	{"VOID AUTH COMP:" , "",""},
	{"VOID AUTH:" , "",""},
	{"OFFLINE:" , "",""},
	{"ADJUST:" , "",""},
	{"SWIPE ERR" , "",""},
	{"TRY AGAIN" , "",""},
	{"Quit Pls [Cancel]" , "",""},
	{"INVALID ENTER" , "",""},
	{"%s $" , "",""},
	{"INSERT/WAVE" , "",""},
	{"WAVE" , "",""},
	{"INSERT" , "",""},
	{"INPUT:" , "",""},
	{"SWIPE" , "",""},
	{"SWIPE/MANUAL" , "",""},
	{"INSERT/SWIPE" , "",""},
	{"SWIPE/WAVE" , "",""},
	{"INSERT/SWIPE/MANUAL" , "",""},
	{"MANUAL/SWIPE/WAVE" , "",""},
	{"MANUAL/WAVE/" , "",""},
	{"SWIPE/INSERT" , "",""},
	{"INSERT/SWIPE/WAVE" , "",""},
	{"INSERT/MANUAL" , "",""},
	{"WAVE/MANUAL" , "",""},
	{"INSERT/WAVE/MANUAL" , "",""},
	{"READ CHIP ERR" , "",""},
	{"Please ESC To Quit" , "",""},
	{"SALE" , "",""},
	{"PREAUTH" , "",""},
	{"Init communication" , "",""},
	{"Please wait..." , "",""},
	{"Comm Fail" , "",""},
	{"Dialing..." , "",""},
	{"Connecting..." , "",""},
	{"Press ESC To Quit" , "",""},
	{"Sending..." , "",""},
	{"Print ISO?" , "",""},
	{"CommSend FAIL" , "",""},
	{"Recving..." , "",""},
	{"CommRecv FAIL" , "",""},
	{"SET COMM" , "",""},
	{"Exterior line:" , "",""},
	{"1.COMMTYPE" , "",""},
	{"2.NII" , "",""},
	{"3.PSTN" , "",""},
	{"4.GPRS" , "",""},
	{"5.CDMA" , "",""},
	{"6.ETH" , "",""},
	{"7.RS232" , "",""},
	{"8.WIFI" , "",""},
	{"9.OTHER" , "",""},
	{"1.MODEM" , "",""},
	{"2.GPRS" , "",""},
	{"3.CDMA" , "",""},
	{"4.RS232" , "",""},
	{"5.ETH" , "",""},
	{"6.WIFI" , "",""},
	{"REVERSAL RESEND" , "",""},
	{"INVALID INPUT.TRY AGAIN!" , "",""},
	{"PPP MODE" , "",""},
	{"Predictive Dialing" , "",""},
	{"Communication timeout:" , "",""},
	{"Redial times:" , "",""},
	{"OFFLINE RESEND" , "",""},
	{"NUM(<=9):" , "",""},
	{"INVALID INPUT,TRY AGAIN!" , "",""},
	{"Wireless dial No.:" , "",""},
	{"USER NAME" , "",""},
	{"USER PASSWORD" , "",""},
	{"Server Domain name" , "",""},
	{"Back-up Domain name" , "",""},
	{"Primary DNS Address" , "",""},
	{"Secondary DNS Address" , "",""},
	{"HOST IP1" , "",""},
	{"HOST IP2" , "",""},
	{"HOST PORT1" , "",""},
	{"HOST PORT2" , "",""},
	{"LOCAL IP" , "",""},
	{"MASK" , "",""},
	{"GATE" , "",""},
	{"ADD TPDU" , "",""},
	{"SEARCH SSID" , "",""},
	{"PLS WAIT..." , "",""},
	{"WIFI PARAM" , "",""},
	{"Password" , "",""},
	{"1.OPEN" , "",""},
	{"2.WEP" , "",""},
	{"3.WPA-PSK" , "",""},
	{"4.WPA2-PSK" , "",""},
	{"5.WPA-CCKM" , "",""},
	{"WIFI MODE" , "",""},
	{"get pan failed %d" , "",""},
	{"EMV initialize" , "",""},
	{"BALANCE" , "",""},
	{"1.Default" , "",""},
	{"2.Savings" , "",""},
	{"3.Cheque/debit" , "",""},
	{"4.Credit" , "",""},
	{"ACCOUNT TYPE" , "",""},
	{"ID CARD" , "",""},
	{"OFFICER" , "",""},
	{"PASSPORT" , "",""},
	{"ENTRY CARD" , "",""},
	{"TEMP IDCARD" , "",""},
	{"OTHER" , "",""},
	{"SHOW CARD" , "",""},
	{"CHOOSE AGAIN" , "",""},
	{"CHOOSE THE APP" , "",""},
	{"Offline Pin:" , "",""},
	{"Last Offline Pin:" , "",""},
	{"Online Pin:" , "",""},
	{"Pls Input Pin:" , "",""},
	{"Do not support offline PIN" , "",""},
	{"Press [Enter]" , "",""},
	{"Pls Input Amount:" , "",""},
	{"PLS REMOVE CARD" , "",""},
	{"Emv Config" , "",""},
	{"Get Emv Config Fail" , "",""},
	{"Set Emv Config Fail" , "",""},
	{"IS USE EC?" , "",""},
	{"PROCESSING..." , "",""},
	{"DECLINE" , "",""},
	{"PLS INSERTIC" , "",""},
	{"PLS SWIPE" , "",""},
	{"READED CARD ERR" , "",""},
	{"ABEND" , "",""},
	{"Input Wrong Pwd for 3 times" , "",""},
	{"PLS Contact issue bank" , "",""},
	{"TRANS FAIL" , "",""},
	{"Pack fail" , "",""},
	{"PACKED FAIL" , "",""},
	{"qPBOC Fail" , "",""},
	{"NOT ACCEPTED" , "",""},
	{"TRANS SUSPEND" , "",""},
	{"READ FAILED" , "",""},
	{"SUSPEND" , "",""},
	{"No auth code in EC-ONLY card" , "",""},
	{"READ ERR" , "",""},
	{"Pls Check If Support Rf" , "",""},
	{"Please try other methods" , "",""},
	{"CANCEL" , "",""},
	{"Error password 3 times" , "",""},
	{"EXP DATE(MMYY):" , "",""},
	{"Pls Input Pin" , "",""},
	{"Get Pin" , "",""},
	{"This CAPK update fialed%d[%d]" , "",""},
	{"This AID update fialed%d[%d]" , "",""},
	{"Input CVV2:" , "",""},
	{"VOID" , "",""},
	{"Adjusted, Not Allow Void" , "",""},
	{"Voided, Not Allow Void" , "",""},
	{"Card No Mismacthing" , "",""},
	{"REVERSAL" , "",""},
	{"|CREVERSAL FAIL" , "",""},
	{"REVERSAL SUCC" , "",""},
	{"AUTH ADVICE" , "",""},
	{"Input Auth ID:" , "",""},
	{"OFFLINE SALE" , "",""},
	{"AUTH CODE:" , "",""},
	{"ADJUST" , "",""},
	{"|CINVAID TRACE" , "",""},
	{"|CIllegal trade conditions" , "",""},
	{"INPUT TOTAL AMOUNT:" , "",""},
	{"CARD NO MISMATCH" , "",""},
	{"ADJUST SUCC" , "",""},
	{"SEND OFFLINE" , "",""},
	{"Processing[%d]..." , "",""},
	{"Pls wait..." , "",""},
	{"Send ok" , "",""},
	{"DUPLICATE? Y/N" , "",""},
	{"BASE AMOUNT:" , "",""},
	{"ENTER TIP:" , "",""},
	{"ENTER AMOUNT:" , "",""},
	{"CORRECT ? Y/N" , "",""},
	{"Nonsupport manual" , "",""},
	{"Load PIN Key Fail" , "",""},
	{"Load MAC Key Fail" , "",""},
	{"Load Data Key Fail" , "",""},
	{"Promt" , "",""},
	{"get SEC_KEY_TYPE_TMK kcv error" , "",""},
	{"get SEC_KEY_TYPE_TPK kcv error" , "",""},
	{"get SEC_KEY_TYPE_TAK kcv error" , "",""},
	{"INITIALIZE" , "",""},
	{"PLS WAIT...." , "",""},
	{"Loading..." , "",""},
	{"1.Close" , "",""},
	{"2.COM Mode" , "",""},
	{"3.FILE Mode" , "",""},
	{"4.Export Log" , "",""},
	{"5.EMV Debug" , "",""},
	{"6.TMS Debug" , "",""},
	{"1.RS232", "",""}, 
	{"2.PINPAD", "",""}, 
	{"3.USB", "",""},
	{"1.Normal", "",""}, 
	{"2.Warning", "",""}, 
	{"3.All", "",""},
	{"Debug" , "",""},
	{"Port Num" , "",""},
	{"Debug Level" , "",""},
	{"1.VOID" , "",""},
	{"2.SETTLE" , "",""},
	{"3.LASTTRX" , "",""},
	{"4.TRACETRX" , "",""},
	{"5.PREAUTH" , "",""},
	{"6.DEBUG" , "",""},
	{"7.SIGNIN" , "",""},
	{"8.QUIT" , "",""},
	{"VISA & MASTER" , "",""},
	{"PRINT LAST" , "",""},
	{"CLEAR REVERSAL" , "",""},
	{"SUCC" , "",""},
	{"1.CLEAR REVERSAL" , "",""},
	{"2.CLEAR LOCK" , "",""},
	{"3.SET NOT SIGNED" , "",""},
	{"4.SET SIGNED" , "",""},
	{"5.CLEAR EMV DATA" , "",""},
	{"6.PINPAD" , "",""},
	{"DO CLEAR" , "",""},
	{"CONFIRM?" , "",""},
	{"CLEAR LOCK" , "",""},
	{"SET NOT SIGNED" , "",""},
	{"SET SIGNED" , "",""},
	{"CLEAR EMV DATA" , "",""},
	{"PROCESSING" , "",""},
	{"COMPLETION" , "",""},
	{"2.CLEAR TRANSLOG" , "",""},
	{"3.CLEAR LOCK" , "",""},
	{"4.SET UNSIGNED" , "",""},
	{"5.SET SIGNED" , "",""},
	{"6.CLEAR EMV" , "",""},
	{"CLEAR" , "",""},
	{"CLEAR LOG" , "",""},
	{"CLEAR TRANS" , "",""},
	{"CLEAR OK" , "",""},
	{"UNLOCK" , "",""},
	{"SET UNSIGNED" , "",""},
	{"OK" , "",""},
	{"DETECT DEV" , "",""},
	{"LOAD SECRITY FAIL" , "",""},
	{"LOAD PINPAD" , "",""},
	{"PINPAD NOT CONNECTTED" , "",""},
	{"Load card reader" , "",""},
	{"Init Rf Card Fail" , "",""},
	{"DOWNLOAD TMK" , "",""},
	{"Connect To Key Pos" , "",""},
	{"[Cancel] to quit" , "",""},
	{"SEND FAIL" , "",""},
	{"Index Err" , "",""},
	{"LEN ERR" , "",""},
	{"INSTALL KEY FAILS" , "",""},
	{"Download Tmk(%d) Ok" , "",""},
	{"1.DOWNLOAD KEY" , "",""},
	{"2.INPUT TMK" , "",""},
	{"3.KEYNO" , "",""},
	{"4.CLEAR" , "",""},
	{"DOWNLOAD KEY" , "",""},
	{"KEY MANAGE" , "",""},
	{"Clear all keys?" , "",""},
	{"Clear Ok" , "",""},
	{"INPUT BY MANUAL" , "",""},
	{"INPUT KEY NO.:" , "",""},
	{"INPUT TMK(32):" , "",""},
	{"LOAD MAINKEY FAIL" , "",""},
	{"LOAD(%d) SUC" , "",""},
	{"SET TMK OK" , "",""},
	{"1.RECEIPT HEAD" , "",""},
	{"2.PAGE" , "",""},
	{"3.OTHER" , "",""},
	{"SET PRINT" , "",""},
	{"1.MERCHANT ID" , "",""},
	{"2.TERMINAL ID" , "",""},
	{"3.MERCHANT NAME" , "",""},
	{"4.MERCHANT ADDR" , "",""},
	{"SET TERMINAL" , "",""},
	{"1.OFFLINE RESEND" , "",""},
	{"2.REVERSAL RESEND" , "",""},
	{"SET RESEND" , "",""},
	{"1.PRINT LAST" , "",""},
	{"2.PRINT ANYONE" , "",""},
	{"3.PRINT OLD SETTLE" , "",""},
	{"4.PRINT SUMMRY" , "",""},
	{"5.PRINT DETAIL" , "",""},
	{"6.PRINT PARAM" , "",""},
	{"DO PRINT" , "",""},
	{"1.LAST TRANS" , "",""},
	{"2.APPOINTED TRANS" , "",""},
	{"3.VIEW SUMMURY" , "",""},
	{"LOOK UP" , "",""},
	{"1.TRACE NO" , "",""},
	{"2.BATCH NO" , "",""},
	{"3.INVOICE NO" , "",""},
	{"4.TRANS COUNT" , "",""},
	{"5.SET PRINT" , "",""},
	{"6.SET VOID" , "",""},
	{"7.RESEND" , "",""},
	{"TRANS PARAM" , "",""},
	{"1.SWIPE ENABLE" , "",""},
	{"2.MANUAL ENABLE" , "",""},
	{"3.WAVE ENABLE" , "",""},
	{"PAYMENT TYPE" , "",""},
	{"1.TRANS ENABLE" , "",""},
	{"2.PAYMENT TYPE" , "",""},
	{"3.TIP ENABLE" , "",""},
	{"ON OFF" , "",""},
	{"1.English" , "",""},
	{"2.Chinese" , "",""},
	{"3.Customized" , "",""},
	{"Language" , "",""},
	{"1.CHANGE PASSWORD" , "",""},
	{"2.SET TIME" , "",""},
	{"3.INITIALIZE" , "",""},
	{"4.PINPAD" , "",""},
	{"5.SET LANGUAGE" , "",""},
	{"SYSTEM" , "",""},
	{"1.LOOK UP" , "",""},
	{"2.VERSION" , "",""},
	{"3.SHOW TVR" , "",""},
	{"4.PRINT ISO" , "",""},
	{"5.EMV LOG" , "",""},
	{"6.TMS" , "",""},
	{"1.MERCHANT" , "",""},
	{"2.COMMUNICATION" , "",""},
	{"3.ON-OF" , "",""},
	{"4.TRANS PARAM" , "",""},
	{"5.KEY MANAGE" , "",""},
	{"6.CLEAR" , "",""},
	{"7.SYSTEM" , "",""},
	{"8.PRINT" , "",""},
	{"MANAGE" , "",""},
	{"QUIT?" , "",""},
	{"SIGN IN" , "",""},
	{"SIGN IN OK" , "",""},
	{"MMDD" , "",""},
	{"TXN Log is Up to %d,Pls Settle" , "",""},
	{"Reboot..." , "",""},
	{"Warning" , "",""},
	{"Translog is out of limit,pls settle" , "",""},
	{"Settle Fail" , "",""},
	{"Pls re settle" , "",""},
	{"Len Of WorkKey Errors" , "",""},
	{"Loading PinKey Errs" , "",""},
	{"Loading MacKey Errs" , "",""},
	{"Loading TrkKey Errs" , "",""},
	{"NONSUPPORT" , "",""},
	{"SET FIELD" , "",""},
	{"GET FIELD" , "",""},
	{"UNPACK ERR" , "",""},
	{"[%d]Field Err" , "",""},
	{"REFUND" , "",""},
	{"OFFLINE" , "",""},
	{"Processing..." , "",""},
	{"BASE" , "",""},
	{"COMM" , "",""},
	{"DIAL" , "",""},
	{"LINE" , "",""},
	{"Update ok" , "",""},
	{"SET KEY INDEX" , "",""},
	{"ENTER KEY INDEX(1-255):" , "",""},
	{"OTHER CONTROL" , "",""},
	{"MAX REFUND AMOUT:" , "",""},
	{"Receipt pages" , "",""},
	{"Num of page(1-3):" , "",""},
	{"INVALID INPUT" , "",""},
	{"TRANS COUNT" , "",""},
	{"INVALID INPUT!" , "",""},
	{"MERCHANT ID" , "",""},
	{"MERCHANT ID(15):" , "",""},
	{"PLS SETTLE FITSTLY" , "",""},
	{"TERMINAL ID" , "",""},
	{"TERMINAL ID(8):" , "",""},
	{"PLS SETTLE" , "",""},
	{"APP NAME" , "",""},
	{"MERCHANT ADDR" , "",""},
	{"MERCHANT NAME" , "",""},
	{"TRACE NO" , "",""},
	{"ENTER:" , "",""},
	{"PLS SETTLE FIRSTLT" , "",""},
	{"BATCH NO" , "",""},
	{"PLS SETTLE FIRST" , "",""},
	{"PINPAD" , "",""},
	{"EXTERNAL PINPAD" , "",""},
	{"BUILDIN SUPPORT ONLY" , "",""},
	{"OFF SEND TYPE" , "",""},
	{"SUPPORT INSERTIC" , "",""},
	{"MANUAL ENABLE" , "",""},
	{"PRINT FAULT REPORT" , "",""},
	{"DEFAULT TRANSACTION" , "",""},
	{"SET VOID" , "",""},
	{"Void Input Password" , "",""},
	{"Capture Card ENABLE" , "",""},
	{"Void Capture Card" , "",""},
	{"0.With Pan" , "",""},
	{"1.Without Pan" , "",""},
	{"Set terminal" , "",""},
	{"PIN MODE" , "",""},
	{"IS PREAUTH SHIELDED PAN" , "",""},
	{"SETTLE CONTROL" , "",""},
	{"PRINT DETAIL" , "",""},
	{"TIP ENABLE" , "",""},
	{"SET TIP RATE" , "",""},
	{"Tip rate(%):" , "",""},
	{"SHOW TVR TSI IN TRANS" , "",""},
	{"SYSTEM MANAGE" , "",""},
	{"Shield pan" , "",""},
	{"SYSTEM PASSWORD:" , "",""},
	{"INPUT PASSWORD:" , "",""},
	{"ERROR,TRY AGAIN" , "",""},
	{"CHANGE PASSWORD" , "",""},
	{"System password:" , "",""},
	{"Transaction password:" , "",""},
	{"Function password:" , "",""},
	{"New password:" , "",""},
	{"Confirm new password:" , "",""},
	{"VERIFY PASSWORD" , "",""},
	{"Verify failed" , "",""},
	{"Old and new are mismatch" , "",""},
	{"CHANGE OK" , "",""},
	{"EXTERN RF" , "",""},
	{"EXTERN RF READER" , "",""},
	{"SUPPORT RF" , "",""},
	{"OFF SEND NUM" , "",""},
	{"ENTER NUM" , "",""},
	{"INVALID NUM,TRY AGAIN!" , "",""},
	{"Pinpad param" , "",""},
	{"TIMEOUT:" , "",""},
	{"0.LOGO" , "",""},
	{"1.STRING" , "",""},
	{"RECEIPT HEAD" , "",""},
	{"PRINT TITLE" , "",""},
	{"VERIFY TRANS PWD" , "",""},
	{"PRINT MINUS" , "",""},
	{"REPRINT SETTLE" , "",""},
	{"ENABLE REPRINT" , "",""},
	{"Software INFO" , "",""},
	{"Version Num:" , "",""},
	{"SYSTEM TIME" , "",""},
	{"DATE(YYYYMMDD):" , "",""},
	{"TIME(HHMMSS):" , "",""},
	{"ACQUIRER NAME" , "",""},
	{"ISSUER NAME" , "",""},
	{"IS SUPPORT?" , "",""},
	{"All datas will be clear" , "",""},
	{"Clear ok" , "",""},
	{"1.SYSTEM PWD" , "",""},
	{"2.USER PWD" , "",""},
	{"PRINT SPECIAL" , "",""},
	{"PRINT TOTAL" , "",""},
	{"SWIPE ENABLE" , "",""},
	{"Trans Param" , "",""},
	{"Invoice NO." , "",""},
	{"SET MAYBANK" , "",""},
	{"Pls settle" , "",""},
	{"SET PRINTF" , "",""},
	{"IS PRINT ISO" , "",""},
	{"TEAR THE RECEIPT..." , "",""},
	{"Swipe" , "",""},
	{"Manual" , "",""},
	{"Chip" , "",""},
	{"Wave" , "",""},
	{"Fall" , "",""},
	{"Card\tNo:" , "",""},
	{"APP:%s" , "",""},
	{"AID:" , "",""},
	{"TC:" , "",""},
	{"REF. NO:%12s" , "",""},
	{"APPR.CODE:%s" , "",""},
	{"BATCH NO:%.6s  TRACE NO:%.6s\r\r" , "",""},
	{"DATE:%.4s/%02x/%02x TIME:%02x:%02x:%02x\r" , "",""},
	{"PIN VERIFIED" , "",""},
	{"NO SIGNATURE REQUIRED" , "",""},
	{"SIGNATURE VERIFY\r" , "",""},
	{"**** MERCHANT COPY ****" , "",""},
	{"**** CUSTOMER COPY ****" , "",""},
	{"**** BANK COPY ****" , "",""},
	{"DUPLICATED" , "",""},
	{"NO SIGNATURE" , "",""},
	{"THANK YOU ! " , "",""},
	{"I HEREBY VERIFY" , "",""},
	{"SIGNATURE" , "",""},
	{"AUTH" , "",""},
	{"AUTH_COMP" , "",""},
	{"AUTH SETTLEMENT" , "",""},
	{"PRE_AUTH_COMP VOID" , "",""},
	{"TXN LIST" , "",""},
	{"DATE:%4.4s/%2.2s/%2.2s  TIME:%2.2s:%2.2s:%2.2s\r" , "",""},
	{"HOST NII:%s  %s\r" , "",""},
	{"TYPE	 CARD NUMBER				AMOUNT	 TRACE" , "",""},
	{"PRINT ALL" , "",""},
	{"NO TRANS RECORD TO PRINT" , "",""},
	{"NO TRANS" , "",""},
	{"NO TRANS TO PRINT" , "",""},
	{"TOTAL" , "",""},
	{"SETTLEMENT" , "",""},
	{"BATCH NO:%.6s\rINVOICE NO:%.6s" , "",""},
	{"***SUMMARY OF CHARGE***" , "",""},
	{"*CLOSE BATCH CONFIRMED*\r" , "",""},
	{"BASE	   %3ld %13s" , "",""},
	{"TIPS	   %3ld %13s" , "",""},
	{"SALE	   %3ld %13s" , "",""},
	{"VOID	   %3ld %13s" , "",""},
	{" ******REPRINT*******" , "",""},
	{"NO RECEIPT" , "",""},
	{"PRINTING..." , "",""},
	{"MERCHANT INFO\r" , "",""},
	{"Merchant Name:%s" , "",""},
	{"Merchant addr:%s" , "",""},
	{"Merchant ID:%s" , "",""},
	{"Terminal ID:%s" , "",""},
	{"App Name:%s" , "",""},
	{"VERSION INFO\r" , "",""},
	{"App Version: %s" , "",""},
	{"TRANS CONTROL\r" , "",""},
	{"Enable Manul:%s" , "",""},
	{"YES" , "",""},
	{"NO" , "",""},
	{"Default Trans:%s" , "",""},
	{"Max Refund Amt:%s" , "",""},
	{"Print Record Record:%s" , "",""},
	{"Offline Send Type:%s" , "",""},
	{"Online" , "",""},
	{"Settle" , "",""},
	{"Offline Send Times:%d" , "",""},
	{"Enter Admin Pwd:%s" , "",""},
	{"SYSTEM CONTROL\r" , "",""},
	{"Trace No.:%s" , "",""},
	{"Batch No.:%s" , "",""},
	{"Print Page:%d" , "",""},
	{"Reversal Times:%d" , "",""},
	{"Max Trans Count:%d" , "",""},
	{"Tip Rate:%d" , "",""},
	{"Print Minus:%s" , "",""},
	{"OTHER\r" , "",""},
	{"Enable Swipe In Void:%s" , "",""},
	{"Enable Pin In Void:%s" , "",""},
	{"Key Index:%s" , "",""},
	{"Encypt Mode:%s" , "",""},
	{"DES" , "",""},
	{"3DES" , "",""},
	{"Comm Type: %s" , "",""},
	{"RS232" , "",""},
	{"MODEM" , "",""},
	{"Tel.1: %s" , "",""},
	{"Tel.2: %s" , "",""},
	{"Tel.3: %s" , "",""},
	{"ETH" , "",""},
	{"Ip Addr.1: %s" , "",""},
	{"Mask: %s" , "",""},
	{"Gate: %s" , "",""},
	{"Wifi Net Mode: NONE" , "",""},
	{"Wifi Net Mode: OPEN" , "",""},
	{"Wifi Net Mode: SHARED" , "",""},
	{"Wifi Net Mode: WAP" , "",""},
	{"Wifi Net Mode: WAP2" , "",""},
	{"User Name: %3.3s****" , "",""},
	{"User Pwd: %3.3s****" , "",""},
	{"Wireless Dialnum: %s" , "",""},
	{"Wireless Mode: %d" , "",""},
	{"Redial Times: %d" , "",""},
	{"Timeout: %d" , "",""},
	{"Is Predial: %s" , "",""},
	{"2.TRANS CONTROL" , "",""},
	{"3.SYSTEM CONTROL" , "",""},
	{"4.COMM" , "",""},
	{"5.VERSION" , "",""},
	{"6.EMV PARA" , "",""},
	{"7.OTHER" , "",""},
	{"PRINT PARA" , "",""},
	{"SALECOMP" , "",""},
	{"TMS" , "",""},
	{"%s: YES" , "",""},
	{"%s: NO" , "",""},
	{"PRINTING" , "",""},
	{"Index:%02x " , "",""},
	{"RID:" , "",""},
	{"	 ExpDate:" , "",""},
	{"POS RECEIPT" , "",""},
	{"TID: xxxxxx%2.2s" , "",""},
	{"MID: %s\r\r" , "",""},
	{"BASE:" , "",""},
	{"TIP:" , "",""},
	{"TOTAL:" , "",""},
	{"SETTLE" , "",""},
	{"Connected to Host" , "",""},
	{"PRINT SETTLE" , "",""},
	{"PLS WAIT" , "",""},
	{"0.NO" , "",""},
	{"1.YES" , "",""},
	{"PRINT DETAIL?" , "",""},
	{"PRINT DETAIL..." , "",""},
	{"SETTLE SUCC" , "",""},
	{"Look Up Summary" , "",""},
	{"TOTAL SALES:" , "",""},
	{"TOTAL REFUNDS:" , "",""},
	{"1.Look up" , "",""},
	{"2.Print" , "",""},
	{"Look up summary" , "",""},
	{"Summary" , "",""},
	{"Print?" , "",""},
	{"Amount Out Of Limit!" , "",""},
	{"Settlement had not commplete,continue?" , "",""},
	{"UPLOAD" , "",""},
	{"UPLOAD [%d]" , "",""},
	{"UPLOADING..." , "",""},
	{"PLEASE WAIT..." , "",""},
	{"UPLOAD SUCC" , "",""},
	{"Amout Out Of Range Per Trans" , "",""},
	{"Total Amout Out Of Range" , "",""},
	{"Set Font" , "",""},
	{"Menu" , "",""},
	{"Please enter PIN:" , "",""},
	{"press [ENTER] to skip" , "",""},
	{"Clear Key To Remove" , "",""},
	{"[ENTER] to skip" , "",""},
	{"[CANCEL] to ESC" , "",""},
	{"[ENTER] for details" , "",""},
	{"[CANCEL]" , "",""},
	{"[ENTER]" , "",""},
	{"ENTER" , "",""},
	{"PRINT SETTLE", "",""},
	{"PLS WAIT" , "",""},
	{"0.NO", "",""},
	{"1.YES", "",""},
	{"PRINT DETAIL?", "",""},
	{"PRINT DETAIL...", "",""},
	{"SETTLE SUCC", "",""},
	{"Look Up Summary", "",""},
	{"TOTAL SALES:", "",""},
	{"TOTAL REFUNDS:", "",""},
	{"1.Look up", "",""},
	{"2.Print", "",""},
	{"Look up summary", "",""},
	{"Summary", "",""},
	{"Print?", "",""},
	{"Amount Out Of Limit!", "",""},
	{"Settlement had not commplete,continue?", "",""},
	{"UPLOAD", "",""},
	{"UPLOAD [%d]", "",""},
	{"UPLOADING...", "",""},
};


#define __OFFSET(BEGIN, END)    ((size_t)(END) - (size_t)(BEGIN))

static unsigned int __time33_hash(const char* strIn, size_t nMaxSizeOfStr=-1){
    unsigned int hash=0x5381;
    char* p = const_cast<char*>(strIn);
    while(*p != '\0'){
        hash += ((hash<<5) + (*p++));
    }
    return hash;
}


static void print_error(const char*file, const char* function,int line,const char* fmt,...){
	printf("@[fn=%s,ln=%d]:",function, line);
	
	va_list args;
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);
	
	printf("\n");
}

static void print_debug(const char*file, const char* function,int line,const char* fmt,...){
	printf("@DEBUG[fn=%s,ln=%d]:",function, line);
	
	va_list args;
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);
	
	printf("\n");
}


#define PRINT_ERROR(...) print_error(__FILE__,__FUNCTION__,__LINE__,__VA_ARGS__);
#define PRINT_DEBUG(...) print_debug(__FILE__,__FUNCTION__,__LINE__,__VA_ARGS__);
struct multi_lang_t
{					
	unsigned int hash;	
	const char* gpszTrText;	
};

static void write_aline(FILE* fp, const char* fmt,...) {
		fseek(fp, 0, SEEK_END);
		va_list args;
		va_start(args, fmt);
		int sizeForWriting = vfprintf(fp,fmt, args);
		va_end(args);
		// PRINT_DEBUG("sizeForWriting=%d", sizeForWriting);
}


static inline multi_lang_t* toMutilLang(std::map<unsigned int, multi_lang_t>::iterator & iter){
	return (multi_lang_t*)(&iter->second);
}

#define __CHECKING_COLLISION

int main(int argc, char* argv[]){
	
	if(argc < 2){
		PRINT_ERROR("please input the arguments !");
		exit(-1);
	}
	
	std::map<unsigned int, multi_lang_t> _hashmap;
    int _count = sizeof(gpszTrText)/sizeof(gpszTrText[0]);
    
	for(int i=0; i!= _count; i++){
        unsigned int _hash = __time33_hash((const char*)gpszTrText[i][0]);

		/// if need checking the collision,please open this MARCO
	#ifdef __CHECKING_COLLISION
		std::map<unsigned int, multi_lang_t>::iterator serached = _hashmap.find(_hash);
		
		if(serached != _hashmap.end()){
			PRINT_ERROR("hash collision! hash=0x%04x, original text=%s, collision text=%s",_hash, toMutilLang(serached)->gpszTrText, (const char*)gpszTrText[i][0]);
			continue;
		}
	#endif
		_hashmap[_hash] = {.hash=_hash, .gpszTrText=(const char*)gpszTrText[i][0]};
	}
	
	
	const char* head={
	"#include <stdint.h>\n"				\
	"#include <stdio.h>\n"				\
	"struct multi_lang_t\n"				\
	"{	"								\
	"	unsigned int hash;\n"			\
	"	const char* gpszTrText[3];\n"	\
	"}MultiLANG[]={"					\
	};

	const char* function_def={
	"#define UN_USED(VA) (void)(VA)\n\n"													\
	"const int SIZE_OF_TABLE = sizeof(MultiLANG)/sizeof(struct multi_lang_t);\n"			\
	"\n"																					\
	"\n"																					\
	"static unsigned int __time33_hash(const char* strIn, size_t nMaxSizeOfStr=-1){			\n\
		UN_USED(nMaxSizeOfStr);																\n\
		unsigned int hash=0x5381;															\n\
		char* p = const_cast<char*>(strIn);													\n\
		while(*p != \'\\0\'){																\n\
			hash += ((hash<<5) + (*p++));													\n\
		}																					\n\
		return hash;																		\n\
	}																						\n"\
	"\n\
	char* tolang(const char* tiptext, int nIdxofOtherLang){																				\n\
		unsigned int _hash = __time33_hash(tiptext);																					\n\
																																		\n\
		int idx = 0;																													\n\
		for(;idx!=SIZE_OF_TABLE;idx++){																									\n\
																																		\n\
			if(_hash != MultiLANG[idx].hash)continue;																					\n\
																																		\n\
			return (char*) ((*MultiLANG[idx].gpszTrText[nIdxofOtherLang])?MultiLANG[idx].gpszTrText[nIdxofOtherLang]:tiptext);			\n\
		}																																\n\
																																		\n\
		return (char*)tiptext;																											\n\
	}																																	\n\
	int getSizeOfLang(){return SIZE_OF_TABLE;}\n"
	};

	const char* fileName = strdup(argv[1]);
	FILE* fp = fopen(fileName, "w");

    write_aline(fp,"%s\n",head);
	std::map<unsigned int, multi_lang_t>::iterator iter = _hashmap.begin();

	for(;iter != _hashmap.end(); iter++){
			write_aline(fp, "{0x%.04x, \"%s\", \"\", \"\"},\n", toMutilLang(iter)->hash, toMutilLang(iter)->gpszTrText);
	}

	write_aline(fp,"%s","};\n");
	write_aline(fp,"%s\n",function_def);
	fclose(fp);
	return 0;
}















