//
//  JCLog.h
//  JCLog_Example
//
//  Created by JC on 2018/5/17.
//  Copyright © 2018年 lswh. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// 控制台打印级数
typedef NS_ENUM(NSInteger, JCLogLevel) {
    JCLogLevelAll       = 1,        //在控制台输出SDK所有日志
    JCLogLevelInfo      = 1 << 1,   //在控制台输出SDK信息日志
    JCLogLevelWarning   = 1 << 2,   //在控制台只输出SDK警告日志
    JCLogLevelError     = 1 << 3,   //在控制台只输出SDK错误日志
    JCLogLevelNone      = 1 << 4,   //在控制台不输出任何日志
};

// Log 的样式
typedef NS_ENUM(NSInteger, JCLogType) {
    JCLogTypeVerbose,
    JCLogTypeInfo,
    JCLogTypeWarning,
    JCLogTypeError,
};

// Log macros
#define JCLogVerbose(mat, ...) [JCLog logType:JCLogTypeVerbose message:mat, ##__VA_ARGS__]
#define JCLogInfo(mat, ...) [JCLog logType:JCLogTypeInfo message:mat, ##__VA_ARGS__]
#define JCLogWarn(mat, ...) [JCLog logType:JCLogTypeWarning message:mat, ##__VA_ARGS__]
#define JCLogError(mat, ...) [JCLog logType:JCLogTypeError message:mat, ##__VA_ARGS__]

#if DEBUG
#define JCDebugLog(mat,...) NSLog((@"DebugLog: " mat),##__VA_ARGS__)
#else
#define JCDebugLog(...)
#endif

@interface JCLog : NSObject

+ (instancetype)sharedInstance;

/**
 *  设置显示的级别
 */
+ (void)setLogLevel:(JCLogLevel)level;

/**
 *  为不同的log添加颜色
 *
 *  默认 Info:浅蓝   Error:红色   warning:橘色
 *  @param color 颜色
 *  @param type  log的type
 */
+ (void)setColor:(UIColor *)color forType:(JCLogType)type;

/**
 *  是否允许开启颜色, 默认开启
 */
+ (void)setColorEnabled:(BOOL)enabled;

/**
 *  是否把日志写入本地，默认不写入
 */
+ (void)enableWriteLogToFile:(BOOL)enabled;

/**
 *  打印
 *
 *  @param type     log type
 *  @param aMessage 消息
 */
+ (void)logType:(JCLogType)type message:(NSString *)aMessage, ...;

/**
 *  当前log文件地址
 */
@property (nonatomic, readonly, copy) NSString *currentLogPath;

@end
