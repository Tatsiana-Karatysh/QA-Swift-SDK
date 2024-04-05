Pod::Spec.new do |spec|
  spec.name = 'QASwiftSDK'
  spec.version = '0.7.1'
  spec.summary = 'QuantActions SDK'
  spec.description = 'The QuantActions SDK allows developers to add all the QuantActions functions to an iOS app including: Automatic data collection, Access processed metrics and insights from the Tap Intelligence Engine (TIE), Enabling device communication, Subscribe to different cohorts.'
 
  spec.homepage = 'https://github.com/QuantActions/QA-Swift-SDK'
  spec.source = { :git => 'https://github.com/QuantActions/QA-Swift-SDK.git', :tag => spec.version }
  spec.documentation_url = 'https://quantactions.github.io/QA-Swift-SDK/documentation/quantactionssdk/'
  spec.authors = { 'QuantActions' => 'development@quantactions.com' }
  spec.license = { :type => "CC-NC-ND", :file => "LICENSE" }

  spec.vendored_frameworks = 'Sources/QuantActionsSDK.xcframework'

  spec.ios.deployment_target = '16.0'
  spec.swift_versions = ['5']

  spec.dependency 'RealmSwift', '~> 10.42.1'
  spec.dependency 'QuantActionsExtraFrameworks', '~> 1.0'

end