//////Hellooo KAKA
//#include <iostream>
//#include <iomanip>
//#include <fstream>
////#include <SFML/System.hpp>
//#include <SFML/Graphics.hpp>
//#include <TGUI/TGUI.hpp>
//#include <thread>
//
//
//#include "ClockModule.h"
//#include "ActivatableClock.h"
//#include "AlarmClock.h"
//#include "TimerClock.h"
//#include "HashAlarm.h"
//
//////Alarm Now Almost Fully Functional minus the need to overload the function isTimeToTing() not to check seconds.
/////Timer needs to be fixed as the ringtone only plays if the userTime_tm is the exact same as the systemTime_tm sec by sec,
/////Which makes it ring for just a sec and then nothing.	
///// 
///// 
///// 
//
//
//
//void checkForAlarms(HashAlarm &clocks)
//{
//	while(true) {
//		for (int i = 0; i < clocks.getCapacity(); i++)
//		{
//			
//			if (clocks.getElementIterator(i).clock.isTimeToRing() && !clocks.getElementIterator(i).clock.getringtoneActive())
//			{
//				
//				
//
//				clocks.getElementIterator(i).clock.activateRingtone();
//			
//				clocks.getElementIterator(i).setisPlaying(true);
//				
//				
//
//
//			}
//			else if(!clocks.getElementIterator(i).clock.isTimeToRing()) {
//				clocks.getElementIterator(i).clock.stopRingtone();
//				
//			}
//		}
//	}
//
//}
//
//int main()
//{
//	HashAlarm ClockStorage;
//
//
//	ofstream fileReadWrite(".\\Alarms.txt");
//
//	sf::RenderWindow mainWin(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "AlarmR");
//	sf::RectangleShape background;
//	sf::Color color; 
//	tgui::Gui gui{ mainWin };
//	color.r = 9;
//	color.g = 38;
//	color.b = 53;
//	background.setFillColor(color);
//	background.setSize(sf::Vector2f(mainWin.getSize().x, mainWin.getSize().y));
//	tgui::Button::Ptr Button = tgui::Button::create();
//	gui.add(Button);
//
//	while (mainWin.isOpen())
//	{
//		sf::Event mainEventHandle;
//		while (mainWin.pollEvent(mainEventHandle))
//		{
//			if (mainEventHandle.type == sf::Event::Closed)
//			{
//				mainWin.close();
//			}
//			gui.handleEvent(mainEventHandle);
//		}
//
//
//		//update
//		mainWin.clear();
//		////Draw Functions Go here...
//		mainWin.draw(background);
//		gui.draw();
//		mainWin.display();
//
//	}
//
//
//
//
//
//	///////FOLLOWING CODE IS PRE PHASE 1 AND PRE GUI....
//
//	AlarmClock clock;
//    TimerClock timer ;
//	
//	
//	std::cout << clock.getSystemTime_tm().tm_hour<< ":" << clock.getSystemTime_tm().tm_min << ":" << clock.getSystemTime_tm().tm_sec << std::endl;  ///%12 to convert to 12H instead of 24H
//	
//	clock.setRingtone("./Ringtones/goofy1.ogg");
//	
//
//	std::cout << timer.getUserTime_tm().tm_hour << ":" << timer.getUserTime_tm().tm_min << ":" << timer.getUserTime_tm().tm_sec << "\n";
//
//
//	
//	
//	std::cout << ClockStorage.numberOfAlarms() << '\n';
//
//	
//		int hours = 0;
//		int min = 0;
//		int sec = 0;
//		int choice;
//		int day = 0;
//		int daysToRing[7];
//		std::cout << clock.getSystemTime_tm().tm_hour << ":" << clock.getSystemTime_tm().tm_min << ":" << clock.getSystemTime_tm().tm_sec << std::endl;  ///%12 to convert to 12H instead of 24H
//
//		timer.setRingtone("./Ringtones/Radar.ogg");
//		std::cout << "Press 1 to set an alarm or 2 to set a timer\n";
//		std::cin >> choice;
//		switch (choice) {
//		case 1:
//			short numODays = 0;
//			while (day != -1 || numODays != 7) {
//				std::cout << "Enter a number (1-7) corresponding to a day of the week and if you're done enter -1\n ";
//				std::cin >> day;
//				daysToRing[numODays] = day;
//				clock.setDaysToRing(daysToRing);
//				if (day == -1) {
//					break;
//				}
//				else numODays++;
//			}
//			std::cout << "Enter hours then minutes then seconds\n";
//			std::cin >> hours >> min >> sec;
//			clock.setAlarmTime(hours, min, sec);
//			break;
//
//		case 2:
//			std::cout << "Enter hours then minutes then seconds For Timer\n";
//			std::cin >> hours >> min >> sec;
//			timer.setTimer(hours, min, sec);
//			break;
//		}
//		
//		std::cout << timer.getUserTime_tm().tm_hour << ":" << timer.getUserTime_tm().tm_min << ":" << timer.getUserTime_tm().tm_sec << "\n";
//		
//		ClockStorage.insertQuadratic(clock.hash()%ClockStorage.getCapacity(), clock);
//
//		std::cout << ClockStorage.to_json(ClockStorage.table) << "<-------JSON STRING OF HASHTABLE\n\n";
//		fileReadWrite << ClockStorage.to_json(ClockStorage.table).dump(2);
//		fileReadWrite.close();
//
//		sf::Thread clockLogicThread(checkForAlarms, ClockStorage);
//			
//		clockLogicThread.launch();


		///////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
//#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <thread>
#include <TGUI/TGUI.hpp>
#include "ClockModule.h"
#include "ActivatableClock.h"
#include "AlarmClock.h"
#include "TimerClock.h"
#include "HashAlarm.h"

		void checkForAlarms(HashAlarm & clocks)
		{

			for (int i = 0; i < clocks.getCapacity(); i++)
			{
				if (clocks.getElementIterator(i).clock.isTimeToRing() && !clocks.getElementIterator(i).clock.getringtoneActive() )
				{
					clocks.getElementIterator(i).clock.activateRingtone();
					clocks.getElementIterator(i).setisPlaying(true);
				}
				else if (!clocks.getElementIterator(i).clock.isTimeToRing()) {
					clocks.getElementIterator(i).clock.stopRingtone();
				}
			}
		}
		int main()
		{
			HashAlarm ClockStorage;
			AlarmClock clock;
			TimerClock timer;
			int daysToRing[7] = {-1};
			int hours = 0, min = 0, sec = 0, choice, day = 0, count = 0, edit_count = 0;
			std::string description = "";
			//sf::RenderWindow mainWin(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "AlarmR");
			sf::RenderWindow mainWin(sf::VideoMode(550, 898), "AlarmR");
			sf::RectangleShape background;
			sf::Color color;
			color.r = 9;
			color.g = 38;
			color.b = 53;
			background.setFillColor(color);
			background.setSize(sf::Vector2f(mainWin.getSize().x, mainWin.getSize().y));
			tgui::GuiSFML gui{ mainWin };
			tgui::Panel::Ptr form = tgui::Panel::create();
			gui.add(form);
			try {
				//form->loadWidgetsFromFile("Resources\\Alarm Forms\\Alarm_Form.txt");
				form->loadWidgetsFromFile("Resources\\Alarm Forms\\MainMenuForm.txt");
			}
			catch (const tgui::Exception e) {
				std::cerr << "TGUI exception: " << e.what() << endl;
				return 1;
			}

			//////
			tgui::Button::Ptr alarmBtn = form->get<tgui::Button>("btn_alarm");
			tgui::Button::Ptr timerBtn = form->get<tgui::Button>("btn_timer");
			alarmBtn->onClick([&] {
				
				
				try {
					form->loadWidgetsFromFile("Resources\\Alarm Forms\\Alarm_Form.txt");
					
				}
				catch (const tgui::Exception e) {
					std::cerr << "TGUI exception: " << e.what() << endl;
					return 1;
				}


				///////////////////////

				// variables 
				tgui::Group::Ptr original_group = form->get<tgui::Group>("Obj_Node");
				tgui::Group::Ptr display[20];
				for (int i = 0; i < 20; ++i) {
					display[i] = tgui::Group::copy(original_group);
					form->add(display[i]);
				}

				tgui::ChildWindow::Ptr childWindow = form->get<tgui::ChildWindow>("Set_Alarm");
				tgui::ChildWindow::Ptr editWindow = form->get<tgui::ChildWindow>("Edit_Alarm");
				tgui::SpinControl::Ptr hourSpin = form->get<tgui::SpinControl>("Set_AlarmHours");
				tgui::SpinControl::Ptr minSpin = form->get<tgui::SpinControl>("Set_AlarmMinutes");
				tgui::ComboBox::Ptr ring = form->get<tgui::ComboBox>("Set_AlarmSound");
				tgui::EditBox::Ptr labelBox = form->get<tgui::EditBox>("Set_AlarmLabel");
				tgui::RadioButton::Ptr AM = form->get<tgui::RadioButton>("Set_AlarmAm");
				tgui::RadioButton::Ptr PM = form->get<tgui::RadioButton>("Set_AlarmPm");
				tgui::CheckBox::Ptr weekdays[7] = {
					form->get<tgui::CheckBox>("Set_AlarmDaySun"),
					form->get<tgui::CheckBox>("Set_AlarmDayMon"),
					form->get<tgui::CheckBox>("Set_AlarmDayTue"),
					form->get<tgui::CheckBox>("Set_AlarmDayWen"),
					form->get<tgui::CheckBox>("Set_AlarmDayThu"),
					form->get<tgui::CheckBox>("Set_AlarmDayFri"),
					form->get<tgui::CheckBox>("Set_AlarmDaySat")
				};

				auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
				std::tm timeInfo;
				localtime_s(&timeInfo, &now);
				int hour = timeInfo.tm_hour;
				//std::cout << hour << "";
				if (hour < 13) {
					AM->setChecked(true);
					//std::cout << "Set AM checkbox" << std::endl;
				}
				else {
					PM->setChecked(true);
					//std::cout << "Set PM checkbox" << std::endl;
				}

				tgui::Button::Ptr addbutton = form->get<tgui::Button>("Add_NewAlarm");
				if (addbutton) {
					addbutton->onPress([&]() {
						tgui::ChildWindow::Ptr childWindow = form->get<tgui::ChildWindow>("Set_Alarm");
						if (childWindow) {
							childWindow->moveToFront(); // Move the child window to the front
							childWindow->setVisible(true);
						}
						});
				}
				else {
					std::cerr << "Button not found.\n";
				}
				tgui::Button::Ptr cnclbutton = form->get<tgui::Button>("Cancle_Alarm");
				if (cnclbutton) {
					cnclbutton->onPress([&]() {
						tgui::ChildWindow::Ptr childWindow = form->get<tgui::ChildWindow>("Set_Alarm");
						childWindow->setVisible(false);
						labelBox->setText("");
						labelBox->setDefaultText("Enter Alarm Name");
						for (int i = 0; i < 7; ++i) {
							if (weekdays[i] && weekdays[i]->isChecked()) {
								weekdays[i]->setChecked(false);  // Assuming 1 corresponds to Sunday
							}
						}
						hourSpin->setValue(0);
						minSpin->setValue(0);
						ring->setSelectedItem("");
						});
				}

				tgui::Button::Ptr saveButton = form->get<tgui::Button>("Save_Alarm");
				if (saveButton) {
					saveButton->onPress([&]() {

						hours = hourSpin->getValue();
						min = minSpin->getValue();
						if (PM->isChecked()) { hours += 12; }
						description = labelBox->getText().toStdString();

						for (int i = 0; i < 7; ++i) {
							if (weekdays[i] && weekdays[i]->isChecked()) {
								daysToRing[i] = (i + 1);  // Assuming 1 corresponds to Sunday
							}
						}

						clock.setDaysToRing(daysToRing);
						for (short i = 0; i < 7; i++) {
							daysToRing[i] = -1;
						}
						clock.setAlarmTime(hours, min, 0);

						std::string selectedRingtone = ring->getSelectedItem().toStdString();
						if (selectedRingtone == "Goofy_ah_easterEgg") {
							clock.setRingtone("./Ringtones/goofy1.ogg");
							std::cout << "Ringtone has been loaded.\n";
						}
						else if (selectedRingtone == "ringtone1") {
							clock.setRingtone("./Ringtones/ringtone1.ogg");
							std::cout << "Ringtone has been loaded.\n";
							std::cout << "Ringtone hasn't been implemented yet.\n\n\n\n or...is it ;)\n";
						}
						else if (selectedRingtone == "Iphone ringtone") {
							clock.setRingtone("./Ringtones/Radar.ogg");
							std::cout << "Ringtone has been loaded.\n";
						}

						ClockStorage.insertQuadratic(clock.hash() % ClockStorage.getCapacity(), clock);
						tgui::ChildWindow::Ptr childRinging = form->get<tgui::ChildWindow>("Ringing");
						bool isRing = false;
						int index = 0;
						for (int i = 0; i < ClockStorage.getCapacity(); i++)
						{
							if (ClockStorage.getElementIterator(i).clock.isTimeToRing() && !ClockStorage.getElementIterator(i).clock.getringtoneActive())
							{
								childRinging->setVisible(true);
								childRinging->moveToFront();
								isRing = true;
								index = i;
								ClockStorage.getElementIterator(i).clock.activateRingtone();
								ClockStorage.getElementIterator(i).setisPlaying(true);
							}
							else if (!ClockStorage.getElementIterator(i).clock.isTimeToRing()) {
								ClockStorage.getElementIterator(i).clock.stopRingtone();
							}
						}
						if (isRing == 1) {
							tgui::Label::Ptr RingingLabel = form->get<tgui::Label>("Ringing_Label");
							tgui::Button::Ptr Stop = form->get<tgui::Button>("Ringing_Stop");
							tgui::Button::Ptr Snooze = form->get<tgui::Button>("Ringing_Snooze");

							RingingLabel->setText(description);
							Stop->onPress([&] {
								std::cout << "stop was clicked\n";
								ClockStorage.getElementIterator(index).clock.stopRingtone();
								childRinging->setVisible(false);
								});
							Snooze->onPress([&] {
								std::cout << "snooze was clicked\n";
								ClockStorage.getElementIterator(index).clock.stopRingtone();
								childRinging->setVisible(false);
								ClockStorage.getElementIterator(index).clock.setAlarmTime(0, 5, 0);
								});
						}


						childWindow->setVisible(false);

						sf::Thread clockLogicThread(checkForAlarms, ClockStorage);
						clockLogicThread.launch();

						labelBox->setText("");
						labelBox->setDefaultText("Enter Alarm Name");
						tgui::CheckBox::Ptr selectedDays[7] =
						{
						display[count]->get<tgui::CheckBox>("Obj_DSU"),
						display[count]->get<tgui::CheckBox>("Obj_DM"),
						display[count]->get<tgui::CheckBox>("Obj_DTU"),
						display[count]->get<tgui::CheckBox>("Obj_DW"),
						display[count]->get<tgui::CheckBox>("Obj_DTH"),
						display[count]->get<tgui::CheckBox>("Obj_DF"),
						display[count]->get<tgui::CheckBox>("Obj_DSA"),
						};
						for (int i = 0; i < 7; ++i) {
							selectedDays[i]->setEnabled(false);
							if (weekdays[i] && weekdays[i]->isChecked()) {
								selectedDays[i]->setChecked(true);  // Check the corresponding checkbox in selectedDays
							}
						}

						for (int i = 0; i < 7; ++i) {
							if (weekdays[i] && weekdays[i]->isChecked()) {
								weekdays[i]->setChecked(false);  // Assuming 1 corresponds to Sunday
							}
						}
						hourSpin->setValue(0);
						minSpin->setValue(0);
						ring->setSelectedItem("");

						if (count < 20) {
							childWindow->moveToFront();
							editWindow->moveToFront();
							display[count]->setVisible(true);
							display[count]->setPosition(70, (count * 163) + 199);
							display[count]->get<tgui::Label>("Obj_Label")->setText(description);
							display[count]->get<tgui::Label>("Obj_Hours")->setText(to_string(hours % 12));
							display[count]->get<tgui::Label>("Obj_Mins")->setText(to_string(min));
							if (PM->isChecked()) {
								display[count]->get<tgui::Label>("PM_AM")->setText("PM");
							}
							else {
								display[count]->get<tgui::Label>("PM_AM")->setText("AM");
							}
							count++;
						}
						});

				}
				tgui::SpinControl::Ptr edithourSpin = form->get<tgui::SpinControl>("Edit_AlarmHours");
				tgui::SpinControl::Ptr editminSpin = form->get<tgui::SpinControl>("Edit_AlarmMinutes");
				tgui::ComboBox::Ptr editring = form->get<tgui::ComboBox>("Edit_AlarmSound");
				tgui::EditBox::Ptr editlabelBox = form->get<tgui::EditBox>("Edit_AlarmLabel");
				tgui::RadioButton::Ptr editAM = form->get<tgui::RadioButton>("Edit_AlarmAm");
				tgui::RadioButton::Ptr editPM = form->get<tgui::RadioButton>("Edit_AlarmPm");
				tgui::CheckBox::Ptr editweekdays[7] = {
					form->get<tgui::CheckBox>("Edit_AlarmDaySun"),
					form->get<tgui::CheckBox>("Edit_AlarmDayMon"),
					form->get<tgui::CheckBox>("Edit_AlarmDayTue"),
					form->get<tgui::CheckBox>("Edit_AlarmDayWen"),
					form->get<tgui::CheckBox>("Edit_AlarmDayThu"),
					form->get<tgui::CheckBox>("Edit_AlarmDayFri"),
					form->get<tgui::CheckBox>("Edit_AlarmDaySat")
				};
				if (display[edit_count]->get<tgui::Button>("Edit_Obj")) {
					display[edit_count]->get<tgui::Button>("Edit_Obj")->onPress([&]() {
						tgui::Button::Ptr editButton = form->get<tgui::Button>("Save_Edit");
						tgui::Button::Ptr cnclEdit = form->get<tgui::Button>("Cancle_Edit");
						editWindow->setVisible(true);
						if (editButton) {
							editButton->onPress([&]() {
								tgui::Label::Ptr objLabel = display[edit_count]->get<tgui::Label>("Obj_Label");
								tgui::Label::Ptr objHours = display[edit_count]->get<tgui::Label>("Obj_Hours");
								tgui::Label::Ptr objMins = display[edit_count]->get<tgui::Label>("Obj_Mins");
								tgui::Label::Ptr pmAmLabel = display[edit_count]->get<tgui::Label>("PM_AM");

								// Update labels with new values
								objLabel->setText(description);
								objHours->setText(to_string(hours % 12));
								objMins->setText(to_string(min));

								// Assuming PM is a global variable, if not, use editPM
								pmAmLabel->setText((PM->isChecked()) ? "PM" : "AM");
								for (int i = 0; i < 7; ++i) {
									if (editweekdays[i] && editweekdays[i]->isChecked()) {
										editweekdays[i]->setChecked(true);  // Assuming 1 corresponds to Sunday
									}
								}
								});
							form->add(display[edit_count]);
						}
						if (cnclEdit) {
							cnclbutton->onPress([&]() {
								std::cout << "cancl was clicked\n";
								editWindow->setVisible(false);
								labelBox->setText("");
								labelBox->setDefaultText("Enter Alarm Name");
								for (int i = 0; i < 7; ++i) {
									if (weekdays[i] && weekdays[i]->isChecked()) {
										weekdays[i]->setChecked(false);  // Assuming 1 corresponds to Sunday
									}
								}
								hourSpin->setValue(0);
								minSpin->setValue(0);
								ring->setSelectedItem("");
								});
						}
						});
					edit_count++;
					if (edit_count >= 20) {
						edit_count = 0; // Reset to 0 or handle it as needed
					}
				}
				//////////////////
				
				});
				timerBtn->onClick([&] {
					
					
					try {
						form->loadWidgetsFromFile("Resources\\Alarm Forms\\timer_Form.txt");
					}
					catch (const tgui::Exception e) {
						std::cerr << "TGUI exception: " << e.what() << endl;
						return 1;
					}
					tgui::SpinControl::Ptr Spin_hr = form->get<tgui::SpinControl>("spin_hr");
					tgui::SpinControl::Ptr Spin_min = form->get<tgui::SpinControl>("spin_min");
					tgui::SpinControl::Ptr Spin_sec = form->get<tgui::SpinControl>("spin_sec");
					tgui::BitmapButton::Ptr btn_stopstart = form->get<tgui::BitmapButton>("btn_stopstart");
					tgui::BitmapButton::Ptr btn_cancel = form->get<tgui::BitmapButton>("btn_cancel");
					tgui::ComboBox::Ptr ringtone = form->get<tgui::ComboBox>("ringtone");
					Spin_hr->setMaximum(23);
					Spin_min->setMaximum(59);
					Spin_sec->setMaximum(59);
					btn_stopstart->setEnabled(false);
					if (btn_cancel) {
						btn_cancel->onPress([&]() {
							Spin_hr->setValue(0);
							Spin_min->setValue(0);
							Spin_sec->setValue(0);
							ringtone->setSelectedItem("");
							});
					}
					if (btn_stopstart) {
						btn_stopstart->onPress([&]() {
							timer.SetStopAlarmActive();
							}
						);
					}
					TimerClock timer;
					std::string selectedRing = ringtone->getSelectedItem().toStdString();
					if (selectedRing == "Goofy_ah_easterEgg") {
						timer.setRingtone("./Ringtones/goofy1.ogg");
						std::cout << "Ringtone has been loaded.\n";
					}
					else if (selectedRing == "ringtone1") {
						timer.setRingtone("./Ringtones/ringtone1.ogg");
						std::cout << "Ringtone has been loaded.\n";
						std::cout << "Ringtone hasn't been implemented yet.\n\n\n\n or...is it ;)\n";
					}
					else if (selectedRing == "Iphone ringtone") {
						timer.setRingtone("./Ringtones/Radar.ogg");
						std::cout << "Ringtone has been loaded.\n";
					}

					
					
					
					
					});



			

			while (mainWin.isOpen())
			{
				sf::Event mainEventHandle;
				while (mainWin.pollEvent(mainEventHandle))
				{
					if (mainEventHandle.type == sf::Event::Closed)
					{
						mainWin.close();
					}

					// Handle other events using TGUI
					gui.handleEvent(mainEventHandle);
				}

				//sf::Thread clockLogicThread(checkForAlarms, &ClockStorage);    /////Re factor thrreading 
				// clockLogicThread.launch();

				checkForAlarms(ClockStorage);

				// Draw
				mainWin.clear();
				// Draw background if needed
				mainWin.draw(background);
				// Draw TGUI widgets
				gui.draw();
				mainWin.display();

			}
		}





		
		
	


	


