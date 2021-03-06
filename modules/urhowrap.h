
#pragma once

#include "Application.h"
#include "Engine.h"
#include "Graphics.h"
#include "InputEvents.h"
#include "ResourceCache.h"
#include "UI.h"
#include "Font.h"
#include "Text.h"
#include "Renderer.h"
#include "Input.h"

using namespace Urho3D;

#if !(defined(WIN32) || defined(_WIN32))
#  define __cdecl
#endif

typedef void(*__cdecl HandlerFunc)(void* userData, StringHash eventType,
                           VariantMap& eventData);

void openUrho3D(bool fullScreen);

void closeUrho3D(void);

Urho3D::Context* getContext(void);

Urho3D::UI* getSubsystemUI(void);

Urho3D::ResourceCache* getSubsystemResourceCache(void);

Urho3D::Font* getFont(const Urho3D::String& fontName);
void parseArguments(void);

void subscribeToEvent(StringHash eventType, HandlerFunc func, void* userData);
void unsubscribeFromEvent(StringHash eventType);

int runMainLoop(void);

Urho3D::ResourceCache* getSubsystemResourceCache(void);
Urho3D::Renderer* getSubsystemRenderer(void);
Urho3D::Input* getSubsystemInput(void);

Urho3D::Application* getApp(void);
Urho3D::Engine* getEngine(void);

template<class T> T* getSubsystem(void) {
  return getApp()->GetSubsystem<T>();
}
