#include "ArmadilloApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<ArmadilloApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

ArmadilloApp::ArmadilloApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(processor_id());

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  ArmadilloApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  ArmadilloApp::associateSyntax(_syntax, _action_factory);
}

ArmadilloApp::~ArmadilloApp()
{
}

void
ArmadilloApp::registerApps()
{
  registerApp(ArmadilloApp);
}

void
ArmadilloApp::registerObjects(Factory & factory)
{
}

void
ArmadilloApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
