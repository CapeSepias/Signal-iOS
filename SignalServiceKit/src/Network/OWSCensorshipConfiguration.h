//
//  Copyright (c) 2021 Open Whisper Systems. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@class OWSHTTPSecurityPolicy;

extern NSString *const OWSFrontingHost_GoogleEgypt;
extern NSString *const OWSFrontingHost_GoogleUAE;
extern NSString *const OWSFrontingHost_GoogleOman;
extern NSString *const OWSFrontingHost_GoogleQatar;
extern NSString *const OWSFrontingHost_GoogleUzbekistan;

@interface OWSCensorshipConfiguration : NSObject

// returns nil if phone number is not known to be censored
+ (nullable instancetype)censorshipConfigurationWithPhoneNumber:(NSString *)e164PhoneNumber;

// returns best censorship configuration for country code. Will return a default if one hasn't
// been specifically configured.
+ (instancetype)censorshipConfigurationWithCountryCode:(NSString *)countryCode;
+ (instancetype)defaultConfiguration;

+ (BOOL)isCensoredPhoneNumber:(NSString *)e164PhoneNumber;

@property (nonatomic, readonly) NSURL *domainFrontBaseURL;
@property (nonatomic, readonly) OWSHTTPSecurityPolicy *domainFrontSecurityPolicy;

@end

NS_ASSUME_NONNULL_END
