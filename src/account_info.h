/**
 * @file    account_info.h
 * @brief   
 * @ref     
 * @author  Taehong, Kim (taehong@somma.kr)
 * @date    2017/12/12 created.
 * @copyright All rights reserved by Yonghwan, Roh.
**/
#pragma once
#include <string>
#include <list>

#include <sal.h>
#include <minwindef.h>
#include <LMaccess.h>


/// @brief account ����
typedef class account
{
public:
	account(_In_ const wchar_t* name,
			_In_ DWORD password_age,
			_In_ DWORD privilege,
			_In_ DWORD flags,
			_In_ const wchar_t* script_path,
			_In_ DWORD last_logon,
			_In_ DWORD num_logons,
			_In_ const wchar_t* sid);

public:
	// ������
	std::wstring name() { return _name; }

	// ������ �н����� ����� ��¥���� ���� ������ �ð�(��)
	DWORD password_age() { return _password_age; }

	// ���� Ÿ��(Administrator, User, Guest)
	const wchar_t* privilege() const;

	// ���� �Ӽ�
	std::wstring attribute_to_string();

	// ����� �α׿½� �����ϴ� ��ũ��Ʈ�� ���
	std::wstring script_path() { return _script_path; };

	// ������ �α��� �ð�
	DWORD last_logon_timestamp() { return _last_logon; }

	// �α��� ���� Ƚ��
	DWORD num_logons() { return _num_logons; }

	// ������ ���� ID
	std::wstring sid() { return _sid; }

private:
	std::wstring _name;
	DWORD		 _privilege;
	DWORD		 _password_age;
	DWORD		 _flags;
	std::wstring _script_path;
	DWORD		 _last_logon;
	DWORD		 _num_logons;
	std::wstring _sid;
} *paccount;




/// @brief `PSID`�� SID ���ڿ��� ��ȯ �Ѵ�.
bool 
psid_to_wstr_sid(
	_In_ PSID sid, 
	_Out_ std::wstring& sid_string
	);

/// @brief  ����� �̸��� ������ ����� ������ ��ȸ �Ѵ�.
bool
get_account_info_by_name(
	_In_ wchar_t* user_name,
	_Out_ LPUSER_INFO_4* user_info
	);

/// @brief  �ý����� ��� ���� ������ �о� �´�. 
bool 
get_account_infos(
	_Out_ std::list<paccount>& accounts
	);