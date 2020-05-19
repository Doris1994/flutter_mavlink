#import "FlutterMavlinkPlugin.h"
#if __has_include(<flutter_mavlink/flutter_mavlink-Swift.h>)
#import <flutter_mavlink/flutter_mavlink-Swift.h>
#else
// Support project import fallback if the generated compatibility header
// is not copied when this plugin is created as a library.
// https://forums.swift.org/t/swift-static-libraries-dont-copy-generated-objective-c-header/19816
#import "flutter_mavlink-Swift.h"
#endif

@implementation FlutterMavlinkPlugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
  [SwiftFlutterMavlinkPlugin registerWithRegistrar:registrar];
}
@end
