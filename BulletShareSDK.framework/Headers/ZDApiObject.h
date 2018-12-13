//
//  ZDApiObject.h
//  BulletShareSDK
//
//  Created by mac on 2018/11/4.
//  Copyright © 2018年 mac. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface ZDApiObject : NSObject

/*! @brief 检查子弹短信是否已被用户安装
 *
 * @return 子弹短信已安装返回YES，未安装返回NO。
 */
+(BOOL)isBulletMessageAPPInstalled;

/*! @brief 获取当前子弹分享SDK的版本号
 *
 * @return 返回当前子弹SDK的版本号
 */
+(NSString *) getApiVersion;

@end


//分享消息类型
typedef enum{
    ZDShareTypeProduct    = 1,          //商品类消息
    ZDShareTypeNews       = 2,          //资讯类消息
    ZDShareTypeVideo      = 3,          //视频类消息
} ZDShareType;

//分享状态
typedef enum {
    ZDShareSuccess        = 0,          //分享成功
    ZDShareFail           = 1,          //分享失败
}ZDShareStatus;

@protocol ZDMessageDelegate <NSObject>

/**
 处理来至子弹短信的请求
 */
- (void)onReq:(ZDShareStatus)status;

@end

@interface ZDMediaMessage : NSObject<ZDMessageDelegate>

+ (ZDMediaMessage *)message;

/** appID
 * @note 长度不能超过512字节
 */
@property (nonatomic,retain) NSString * appID;

/** 标题
 * @note 长度不能超过512字节
 */
@property (nonatomic,retain) NSString * title;

/** 描述内容
 * @note 长度不能超过1K
 * 商品类型此处为商品价格
 */
@property (nonatomic,retain) NSString * descript;

/** 点击链接
 * @note 大小不能超过512字节
 */
@property (nonatomic,retain) NSString * linkURL;

/** 分享图片
 *
 * @note 大小不能超过32K
 */
@property (nonatomic,retain) NSString * imageURL;

/**分享消息的类型
 *
 * @note 大小不能超过32K
 */
@property (nonatomic,assign) ZDShareType shareType;

/*! @brief 发送分享请求
 *
 */
- (void)sendRep;

/*! @brief 处理子弹短信通过URL启动App时传递的数据
 *
 * 需要在 application:openURL:sourceApplication:annotation:或者application:handleOpenURL中调用。
 * @param url 子弹短信启动第三方应用时传递过来的URL
 * @param delegate  ZDMediaMessage对象，用来接收微信触发的消息。
 * @return 成功返回YES，失败返回NO。
 */
+ (BOOL)handleOpenURL:(NSURL *)url delegate:(id<ZDMessageDelegate>)delegate;

@end


