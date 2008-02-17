#ifndef ENUM_VALUE_H
#define ENUM_VALUE_H

#include "value.h"
#include "param-spec-helper.h"
#include <list>

namespace ns3 {

class EnumValue : public Value
{
public:
  EnumValue (int v);
  void Set (int v);
  int Get (void) const;

  virtual PValue Copy (void) const;
  virtual std::string SerializeToString (Ptr<const AttributeChecker> checker) const;
  virtual bool DeserializeFromString (std::string value, Ptr<const AttributeChecker> checker);

  EnumValue (PValue value);
  operator PValue () const;
private:
  int m_v;
};

class EnumParamSpec : public ParamSpec {};
class EnumChecker : public AttributeChecker
{
public:
  EnumChecker ();

  void AddDefault (int v, std::string name);
  void Add (int v, std::string name);

  virtual bool Check (PValue value) const;

private:
  friend class EnumValue;
  typedef std::list<std::pair<int,std::string> > ValueSet;
  ValueSet m_valueSet;
};

template <typename T1>
Ptr<ParamSpec> MakeEnumParamSpec (T1 a1);

template <typename T1, typename T2>
Ptr<ParamSpec> MakeEnumParamSpec (T1 a1, T2 a2);

Ptr<AttributeChecker> MakeEnumChecker (int v1, std::string n1,
				       int v2 = 0, std::string n2 = "",
				       int v3 = 0, std::string n3 = "",
				       int v4 = 0, std::string n4 = "",
				       int v5 = 0, std::string n5 = "",
				       int v6 = 0, std::string n6 = "",
				       int v7 = 0, std::string n7 = "",
				       int v8 = 0, std::string n8 = "",
				       int v9 = 0, std::string n9 = "",
				       int v10 = 0, std::string n10 = "",
				       int v11 = 0, std::string n11 = "",
				       int v12 = 0, std::string n12 = "");


} // namespace ns3

namespace ns3 {

template <typename T1>
Ptr<ParamSpec> MakeEnumParamSpec (T1 a1)
{
  return MakeParamSpecHelper<EnumParamSpec,EnumValue> (a1);
}

template <typename T1, typename T2>
Ptr<ParamSpec> MakeEnumParamSpec (T1 a1, T2 a2)
{
  return MakeParamSpecHelper<EnumParamSpec,EnumValue> (a1, a2);
}

} // namespace ns3

#endif /* ENUM_VALUE_H */
