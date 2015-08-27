//
//  ZQFCycleView.h
//
//  iOS上的简单无限轮播图
//  gitHub地址：https://github.com/zengqingf/ZQFCycleView
//
//  Created by 曾庆福 on 15/7/24.
//  Copyright (c) 2015年 zengqingfu. All rights reserved.
//

#import <UIKit/UIKit.h>


@class ZQFCycleView;

@protocol ZQFCycleViewDelegate <NSObject>

@required
//返回图片的个数
- (NSInteger)countOfCycleView:(ZQFCycleView *)cycleView;

@optional
//设置imageview-这里可以使用SDImageView 等等第三方库哦
- (void)cycleView:(ZQFCycleView *)cycleView willDisplayImageView:(UIImageView *)imageView index:(NSInteger)index;
//滑动停止的时候显示标签
- (void)cycleView:(ZQFCycleView *)cycleView didDisplayTitleLabel:(UILabel *)titleLabel index:(NSInteger)index;
//点击触发的
- (void)cycleView:(ZQFCycleView *)cycleView didTouchImageView:(UIImageView *)imageView  titleLabel:(UILabel *)titleLabel index:(NSInteger)index;

@end


@interface ZQFCycleView : UIView

@property (assign, readonly)NSTimeInterval ti;//定时器间隔时间
- (instancetype)initWithFrame:(CGRect)frame delegate:(id <ZQFCycleViewDelegate>) delegate;
- (void)reload;//当数据源发生变化时，建议调用一下
- (BOOL)startPlayWithTimeInterval:(NSTimeInterval)ti;//定时器开始播放，当视图即将出现的时候记得调用
- (void)stopPlay;//当视图将要消失的时候记得调用

@end
