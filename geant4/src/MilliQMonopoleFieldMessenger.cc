//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: MilliQMonopoleFieldMessenger.cc 68036 2013-03-13 14:13:45Z gcosmo $
//
/// \file exoticphysics/monopole/src/MilliQMonopoleFieldMessenger.cc
/// \brief Implementation of the MilliQMonopoleFieldMessenger class
//
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// =======================================================================
// Created:  15 Jun 2010, B. Bozsogi
// =======================================================================

#include "MilliQMonopoleFieldMessenger.hh"

#include "MilliQMonopoleFieldSetup.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MilliQMonopoleFieldMessenger::MilliQMonopoleFieldMessenger(MilliQMonopoleFieldSetup * fld)
:G4UImessenger(),
 fField(fld),
 fFieldDir(0),
 fSetFieldCmd(0)
 
{ 
  fFieldDir = new G4UIdirectory("/testex/fld/");
  fFieldDir->SetGuidance("field setup commands");
      
  fSetFieldCmd = new G4UIcmdWithADoubleAndUnit("/testex/fld/setField",this);
  fSetFieldCmd->SetGuidance("Define magnetic field.");
  fSetFieldCmd->SetGuidance("Magnetic field will be in Z direction.");
  fSetFieldCmd->SetParameterName("Bz",false);
  fSetFieldCmd->SetUnitCategory("Magnetic flux density");
  fSetFieldCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MilliQMonopoleFieldMessenger::~MilliQMonopoleFieldMessenger()
{
  delete fSetFieldCmd;
  delete fFieldDir;  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void MilliQMonopoleFieldMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  if( command == fSetFieldCmd )
   { fField->SetMagField(fSetFieldCmd->GetNewDoubleValue(newValue));}
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
