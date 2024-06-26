//
//  QsignSafeKeyApi.h
//  QsignSafeKey
//
//  Created by 卖女孩的小火柴 on 2021/3/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger, QsignKeyErrorCode) {
    INITERROR= 0,   //初始化失败
    CREATEKEYERROR,//生成密钥失败
    ENCRYPTERROR,//加密失败
    DECRYPTERROR,//解密失败
    PARAMERROR,//入参有误
    HAVEKEYERROR,//密钥区已存在
    SIGNERROR//签名失败
};
//成功回调
typedef void (^NotaryKeySuccessCompletion) (NSString* maintext);
//失败回调
typedef void (^NotaryKeyErrorCompletion) (QsignKeyErrorCode errorcode,NSString* msg);
@interface QsignSafeKeyApi : NSObject
+(instancetype)shareInstance;
/*
* 生成密钥
   idnumber 身份证号 不能为空
   forced  是否强制生成密钥
*/
-(void)createNotaryKey:(NSString*)idnumber forceCreate:(BOOL)forced successHandle:(NotaryKeySuccessCompletion)successhandle errorHandle:(NotaryKeyErrorCompletion)errorHandle;
/*
*  加密
   idnumber 身份证号 不能为空
   originStr 源数据
   pubKey  公钥16进制
*/
-(void)encryptNotary:(NSString*)idnumber originStr:(NSString*)origin pubKey:(NSString*)pubkey successHandle:(NotaryKeySuccessCompletion)successhandle errorHandle:(NotaryKeyErrorCompletion)errorHandle;
/*
*  解密
   idnumber 身份证号 不能为空
   cipherstr 密文
*/
-(void)decryptNotary:(NSString*)idnumber cipherStr:(NSString*)cipherstr  successHandle:(NotaryKeySuccessCompletion)successhandle errorHandle:(NotaryKeyErrorCompletion)errorHandle;
/*
*  签名
   idnumber 身份证号 不能为空
   originStr 签名数据 不能为空
   pubkey  公钥  不能为空
*/
-(void)signNotary:(NSString*)idnumber originStr:(NSString*)originStr pubkey:(NSString*)pubStr  successHandle:(NotaryKeySuccessCompletion)successhandle errorHandle:(NotaryKeyErrorCompletion)errorHandle;

/*
*  验证签名
   originStr 签名原数据 不能为空
   signStr   签名后的数据 不能为空
   pubkey    公钥  不能为空
*/
-(BOOL)verifyNotary:(NSString*)originStr signStr:(NSString*)signStr pubkey:(NSString*)pubStr;

/*
*  查询是否存在密钥
   idnumber 身份证号 不能为空
*/
-(BOOL)checkNotaryKey:(NSString*)idnumber;


@end

NS_ASSUME_NONNULL_END
