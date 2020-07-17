import Flutter
import UIKit

public class SwiftFlutterMavlinkPlugin: NSObject, FlutterPlugin {
  public static func register(with registrar: FlutterPluginRegistrar) {
    let channel = FlutterMethodChannel(name: "flutter_mavlink", binaryMessenger: registrar.messenger())
    let instance = SwiftFlutterMavlinkPlugin()
    registrar.addMethodCallDelegate(instance, channel: channel)
  }

  public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
    result("iOS " + UIDevice.current.systemVersion)
  }

  public func dummyMethodToEnforceBundling() {
    native_add(1,1);
  }
}
