#pragma once
/// <summary>
/// Base class for each component 
/// </summary>

class Component
{
public:
   virtual ~Component() = default;
   virtual void init(int x) = 0;
   virtual void update(int x) = 0;
   virtual void draw() = 0;
};