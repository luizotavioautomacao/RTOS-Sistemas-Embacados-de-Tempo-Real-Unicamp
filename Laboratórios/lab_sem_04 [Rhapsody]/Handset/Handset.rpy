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
	- _name = "Handset";
	- _objectCreation = "101646027422018156902310";
	- _umlDependencyID = "2289";
	- _lastID = 3;
	- _UserColors = { IRPYRawContainer 
		- size = 16;
		- value = 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 
	}
	- _defaultSubsystem = { ISubsystemHandle 
		- _m2Class = "ISubsystem";
		- _filename = "RequirementsPkg.sbs";
		- _subsystem = "";
		- _class = "";
		- _name = "RequirementsPkg";
		- _id = GUID 5c03d259-651c-4045-8146-764a17210e79;
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
			- _count = 10;
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
		- size = 4;
		- value = 
		{ ISubsystem 
			- fileName = "RequirementsPkg";
			- _id = GUID 5c03d259-651c-4045-8146-764a17210e79;
		}
		{ ISubsystem 
			- fileName = "AnalysisPkg";
			- _id = GUID abc81f71-4b1c-477a-b10f-ba431b27b656;
		}
		{ ISubsystem 
			- fileName = "ArchitecturePkg";
			- _id = GUID f7fbc8bd-cc41-4de3-9b10-f367c98cc4b8;
		}
		{ ISubsystem 
			- fileName = "SubsystemsPkg";
			- _id = GUID bf4919d3-b413-4f12-abd7-3a2dce17386d;
		}
	}
	- Diagrams = { IRPYRawContainer 
		- size = 1;
		- value = 
		{ IDiagram 
			- _id = GUID f45a3dec-3b43-447f-ad83-ac65f6463d76;
			- _myState = 8192;
			- _name = "Model1";
			- _objectCreation = "101646227422018156900310";
			- _umlDependencyID = "2124";
			- _lastModifiedTime = "3.27.2018::13:30:58";
			- _graphicChart = { CGIClassChart 
				- _id = GUID c84536fa-e06d-4a5b-bd77-d8f2c8722ffd;
				- m_type = 0;
				- m_pModelObject = { IHandle 
					- _m2Class = "IDiagram";
					- _id = GUID f45a3dec-3b43-447f-ad83-ac65f6463d76;
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
					- _id = GUID f7179a30-a4b5-4bc6-b41c-24599f50e254;
					- m_type = 78;
					- m_pModelObject = { IHandle 
						- _m2Class = "IClass";
						- _filename = "RequirementsPkg.sbs";
						- _subsystem = "RequirementsPkg";
						- _class = "";
						- _name = "TopLevel";
						- _id = GUID f84e88ee-ec91-4bb3-9f88-4af50e167c4a;
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
				- m_pRoot = GUID f7179a30-a4b5-4bc6-b41c-24599f50e254;
				- m_currentLeftTop = 0 0 ;
				- m_currentRightBottom = 0 0 ;
			}
			- _defaultSubsystem = { IHandle 
				- _m2Class = "ISubsystem";
				- _filename = "RequirementsPkg.sbs";
				- _subsystem = "";
				- _class = "";
				- _name = "RequirementsPkg";
				- _id = GUID 5c03d259-651c-4045-8146-764a17210e79;
			}
		}
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

