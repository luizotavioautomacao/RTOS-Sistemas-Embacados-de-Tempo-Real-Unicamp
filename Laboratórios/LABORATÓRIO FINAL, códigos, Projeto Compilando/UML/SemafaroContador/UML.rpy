I-Logix-RPY-Archive version 8.5.2 Modeler C++ 1159120
{ IProject 
	- _id = GUID 8cd5127b-afc2-46e1-8d01-72c9949dba97;
	- _myState = 8192;
	- _properties = { IPropertyContainer 
		- Subjects = { IRPYRawContainer 
			- size = 1;
			- value = 
			{ IPropertySubject 
				- _Name = "Browser";
				- Metaclasses = { IRPYRawContainer 
					- size = 1;
					- value = 
					{ IPropertyMetaclass 
						- _Name = "Settings";
						- Properties = { IRPYRawContainer 
							- size = 1;
							- value = 
							{ IProperty 
								- _Name = "ShowPredefinedPackage";
								- _Value = "False";
								- _Type = Bool;
							}
						}
					}
				}
			}
		}
	}
	- _name = "UML";
	- _objectCreation = "46312271514201815-1400546";
	- _umlDependencyID = "1863";
	- _lastID = 3;
	- _UserColors = { IRPYRawContainer 
		- size = 16;
		- value = 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 
	}
	- _defaultSubsystem = { ISubsystemHandle 
		- _m2Class = "ISubsystem";
		- _filename = "SubsystemsPkg.sbs";
		- _subsystem = "";
		- _class = "";
		- _name = "SubsystemsPkg";
		- _id = GUID bf4919d3-b413-4f12-abd7-3a2dce17386d;
	}
	- _component = { IHandle 
		- _m2Class = "IComponent";
		- _filename = "DefaultComponent.cmp";
		- _subsystem = "";
		- _class = "";
		- _name = "DefaultComponent";
		- _id = GUID fbdbcdcd-f746-41e6-97bb-a3af5bc4ad06;
	}
	- Multiplicities = { IRPYRawContainer 
		- size = 4;
		- value = 
		{ IMultiplicityItem 
			- _name = "1";
			- _count = 13;
		}
		{ IMultiplicityItem 
			- _name = "*";
			- _count = -1;
		}
		{ IMultiplicityItem 
			- _name = "0,1";
			- _count = -1;
		}
		{ IMultiplicityItem 
			- _name = "1..*";
			- _count = -1;
		}
	}
	- Subsystems = { IRPYRawContainer 
		- size = 1;
		- value = 
		{ ISubsystem 
			- fileName = "SubsystemsPkg";
			- _id = GUID bf4919d3-b413-4f12-abd7-3a2dce17386d;
		}
	}
	- Diagrams = { IRPYRawContainer 
		- size = 0;
	}
	- Components = { IRPYRawContainer 
		- size = 1;
		- value = 
		{ IComponent 
			- fileName = "DefaultComponent";
			- _id = GUID fbdbcdcd-f746-41e6-97bb-a3af5bc4ad06;
		}
	}
}

