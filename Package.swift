// swift-tools-version: 5.8

import PackageDescription

let package = Package(
    name: "QASwiftSDK",
    platforms: [
        .iOS(.v15)
    ],
    products: [
        .library(
            name: "QASwiftSDK",
            targets: ["QASwiftSDK", "QuantActionsSDK"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/FleksySDK/FleksySDK-iOS", exact: "4.13.0"),
        .package(url: "https://github.com/realm/realm-swift.git", exact: "10.42.1"),
    ],
    targets: [
        .target(
            name: "QASwiftSDK",
            dependencies: [
                .product(name: "FleksySDK", package: "FleksySDK-iOS"),
                .product(name: "Realm", package: "realm-swift"),
                .product(name: "RealmSwift", package: "realm-swift"),
                "QuantActionsSDK"
            ]
        ),
        .binaryTarget(
            name: "QuantActionsSDK",
            path: "./Sources/QuantActionsSDK.xcframework"
        ),
    ]
)
