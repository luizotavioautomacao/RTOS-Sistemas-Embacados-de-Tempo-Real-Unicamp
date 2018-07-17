I-Logix-RPY-Archive version 8.5.2 Modeler C++ 1159120
{ IProject 
	- _id = GUID e8ab8929-816e-4560-8e22-57c2b7781392;
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
	- _name = "Project";
	- _objectCreation = "543043114562018195801554";
	- _umlDependencyID = "2319";
	- _lastID = 13;
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
		- _id = GUID 033856b9-df0d-443b-812f-2b94915892a2;
	}
	- _component = { IHandle 
		- _m2Class = "IComponent";
		- _filename = "DefaultComponent.cmp";
		- _subsystem = "";
		- _class = "";
		- _name = "DefaultComponent";
		- _id = GUID bfb6830b-232e-422f-bb3c-dfaedb98fa50;
	}
	- Multiplicities = { IRPYRawContainer 
		- size = 4;
		- value = 
		{ IMultiplicityItem 
			- _name = "1";
			- _count = -1;
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
		- size = 7;
		- value = 
		{ ISubsystem 
			- fileName = "SubsystemsPkg";
			- _id = GUID 033856b9-df0d-443b-812f-2b94915892a2;
		}
		{ ISubsystem 
			- fileName = "AnalysisPkg";
			- _id = GUID 8a0a3b29-1a36-4acb-b2eb-269925f73411;
		}
		{ ISubsystem 
			- fileName = "RequirementsPkg_0";
			- _id = GUID b1f44195-2348-401f-95c8-e9417a575ffc;
		}
		{ ISubsystem 
			- fileName = "ArchitecturePkg";
			- _id = GUID d03fa559-1378-4947-91ed-fe0d09706858;
		}
		{ ISubsystem 
			- fileName = "protocolo";
			- _id = GUID c739ba7d-5fc3-43a7-85b2-ea3226843713;
		}
		{ ISubsystem 
			- fileName = "serial";
			- _id = GUID 68672336-8aae-45e7-ab8c-a2350f54a006;
		}
		{ ISubsystem 
			- fileName = "Sources";
			- _id = GUID 49f4e301-16dd-46de-8dcd-a7ee3a057aec;
		}
	}
	- Diagrams = { IRPYRawContainer 
		- size = 1;
		- value = 
		{ IDiagram 
			- _id = GUID 9f2a57be-eda3-4e68-bdf3-f3d17114b3da;
			- _myState = 8192;
			- _name = "Model1";
			- _objectCreation = "543101914562018195213554";
			- _umlDependencyID = "2138";
			- _lastModifiedTime = "4.23.2018::16:19:38";
			- _graphicChart = { CGIClassChart 
				- _id = GUID 09cae6a9-d092-4bec-91c8-ca1a064ed0eb;
				- m_type = 0;
				- m_pModelObject = { IHandle 
					- _m2Class = "IDiagram";
					- _id = GUID 9f2a57be-eda3-4e68-bdf3-f3d17114b3da;
				}
				- m_pParent = ;
				- m_name = { CGIText 
					- m_str = "";
					- m_style = "Arial" 10 0 0 0 1 ;
					- m_color = { IColor 
						- m_fgColor = 0;
						- m_bgColor = 0;
						- m_bgFlag = 0;
					}
					- m_position = 1 0 0  ;
					- m_nIdent = 0;
					- m_bImplicitSetRectPoints = 0;
					- m_nOrientationCtrlPt = 8;
				}
				- m_drawBehavior = 0;
				- m_bIsPreferencesInitialized = 0;
				- elementList = 1;
				{ CGIClass 
					- _id = GUID d912b852-3000-42a4-9cba-373d6ebcd0cf;
					- m_type = 78;
					- m_pModelObject = { IHandle 
						- _m2Class = "IClass";
						- _filename = "SubsystemsPkg.sbs";
						- _subsystem = "SubsystemsPkg";
						- _class = "";
						- _name = "TopLevel";
						- _id = GUID 48d74d6a-a95a-4636-9998-2e3c211a18eb;
					}
					- m_pParent = ;
					- m_name = { CGIText 
						- m_str = "TopLevel";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nOrientationCtrlPt = 5;
					}
					- m_drawBehavior = 0;
					- m_bIsPreferencesInitialized = 0;
					- m_AdditionalLabel = { CGIText 
						- m_str = "";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nOrientationCtrlPt = 1;
					}
					- m_polygon = 0 ;
					- m_nNameFormat = 0;
					- m_nIsNameFormat = 0;
					- Attrs = { IRPYRawContainer 
						- size = 0;
					}
					- Operations = { IRPYRawContainer 
						- size = 0;
					}
				}
				
				- m_access = 'Z';
				- m_modified = 'N';
				- m_fileVersion = "";
				- m_nModifyDate = 0;
				- m_nCreateDate = 0;
				- m_creator = "";
				- m_bScaleWithZoom = 1;
				- m_arrowStyle = 'S';
				- m_pRoot = GUID d912b852-3000-42a4-9cba-373d6ebcd0cf;
				- m_currentLeftTop = 0 0 ;
				- m_currentRightBottom = 0 0 ;
			}
			- _defaultSubsystem = { IHandle 
				- _m2Class = "ISubsystem";
				- _filename = "SubsystemsPkg.sbs";
				- _subsystem = "";
				- _class = "";
				- _name = "SubsystemsPkg";
				- _id = GUID 033856b9-df0d-443b-812f-2b94915892a2;
			}
		}
	}
	- Components = { IRPYRawContainer 
		- size = 1;
		- value = 
		{ IComponent 
			- fileName = "DefaultComponent";
			- _id = GUID bfb6830b-232e-422f-bb3c-dfaedb98fa50;
		}
	}
}

