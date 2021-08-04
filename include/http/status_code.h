#pragma once

namespace http
{
	enum class status_code
	{
		sc_continue						   = 100,
		sc_switching_protocols			   = 101,
		sc_processing					   = 102,
		sc_early_hints					   = 103,
		sc_ok							   = 200,
		sc_created						   = 201,
		sc_accepted						   = 202,
		sc_non_authoritative_information   = 203,
		sc_no_content					   = 204,
		sc_reset_content				   = 205,
		sc_partial_content				   = 206,
		sc_multi_status					   = 207,
		sc_already_reported				   = 208,
		sc_im_used						   = 226,
		sc_multiple_choices				   = 300,
		sc_moved_permanently			   = 301,
		sc_found						   = 302,
		sc_see_other					   = 303,
		sc_not_modified					   = 304,
		sc_use_proxy					   = 305,
		sc_switch_proxy					   = 306,
		sc_temporary_redirect			   = 307,
		sc_permanent_redirect			   = 308,
		sc_bad_request					   = 400,
		sc_unauthorized					   = 401,
		sc_payment_required				   = 402,
		sc_forbidden					   = 403,
		sc_not_found					   = 404,
		sc_method_not_allowed			   = 405,
		sc_not_acceptable				   = 406,
		sc_proxy_authentication_required   = 407,
		sc_request_timeout				   = 408,
		sc_conflict						   = 409,
		sc_gone							   = 410,
		sc_length_required				   = 411,
		sc_precondition_failed			   = 412,
		sc_payload_too_large			   = 413,
		sc_uri_too_long					   = 414,
		sc_unsupported_media_type		   = 415,
		sc_range_not_satisfiable		   = 416,
		sc_expectation_failed			   = 417,
		sc_im_a_teapot					   = 418,
		sc_misdirected_request			   = 421,
		sc_unprocessable_entity			   = 422,
		sc_locked						   = 423,
		sc_failed_dependency			   = 424,
		sc_too_early					   = 425,
		sc_upgrade_required				   = 426,
		sc_precondition_required		   = 428,
		sc_too_many_requests			   = 429,
		sc_request_header_fields_too_large = 431,
		sc_unavailable_for_legal_reasons   = 451,
		sc_internal_server_error		   = 500,
		sc_not_implemented				   = 501,
		sc_bad_gateway					   = 502,
		sc_service_unavailable			   = 503,
		sc_gateway_timeout				   = 504,
		sc_http_version_not_supported	   = 505,
		sc_variant_also_negotiates		   = 506,
		sc_insufficient_storage			   = 507,
		sc_loop_detected				   = 508,
		sc_not_extended					   = 510,
		sc_network_authentication_required = 511,
	};

	std::ostream& operator<<(std::ostream& stm, status_code const& val)
	{
		switch (val)
			{
			case status_code::sc_continue: return stm << "sc_continue";
			case status_code::sc_switching_protocols: return stm << "sc_switching_protocols";
			case status_code::sc_processing: return stm << "sc_processing";
			case status_code::sc_early_hints: return stm << "sc_early_hints";
			case status_code::sc_ok: return stm << "sc_ok";
			case status_code::sc_created: return stm << "sc_created";
			case status_code::sc_accepted: return stm << "sc_accepted";
			case status_code::sc_non_authoritative_information: return stm << "sc_non_authoritative_information";
			case status_code::sc_no_content: return stm << "sc_no_content";
			case status_code::sc_reset_content: return stm << "sc_reset_content";
			case status_code::sc_partial_content: return stm << "sc_partial_content";
			case status_code::sc_multi_status: return stm << "sc_multi_status";
			case status_code::sc_already_reported: return stm << "sc_already_reported";
			case status_code::sc_im_used: return stm << "sc_im_used";
			case status_code::sc_multiple_choices: return stm << "sc_multiple_choices";
			case status_code::sc_moved_permanently: return stm << "sc_moved_permanently";
			case status_code::sc_found: return stm << "sc_found";
			case status_code::sc_see_other: return stm << "sc_see_other";
			case status_code::sc_not_modified: return stm << "sc_not_modified";
			case status_code::sc_use_proxy: return stm << "sc_use_proxy";
			case status_code::sc_switch_proxy: return stm << "sc_switch_proxy";
			case status_code::sc_temporary_redirect: return stm << "sc_temporary_redirect";
			case status_code::sc_permanent_redirect: return stm << "sc_permanent_redirect";
			case status_code::sc_bad_request: return stm << "sc_bad_request";
			case status_code::sc_unauthorized: return stm << "sc_unauthorized";
			case status_code::sc_payment_required: return stm << "sc_payment_required";
			case status_code::sc_forbidden: return stm << "sc_forbidden";
			case status_code::sc_not_found: return stm << "sc_not_found";
			case status_code::sc_method_not_allowed: return stm << "sc_method_not_allowed";
			case status_code::sc_not_acceptable: return stm << "sc_not_acceptable";
			case status_code::sc_proxy_authentication_required: return stm << "sc_proxy_authentication_required";
			case status_code::sc_request_timeout: return stm << "sc_request_timeout";
			case status_code::sc_conflict: return stm << "sc_conflict";
			case status_code::sc_gone: return stm << "sc_gone";
			case status_code::sc_length_required: return stm << "sc_length_required";
			case status_code::sc_precondition_failed: return stm << "sc_precondition_failed";
			case status_code::sc_payload_too_large: return stm << "sc_payload_too_large";
			case status_code::sc_uri_too_long: return stm << "sc_uri_too_long";
			case status_code::sc_unsupported_media_type: return stm << "sc_unsupported_media_type";
			case status_code::sc_range_not_satisfiable: return stm << "sc_range_not_satisfiable";
			case status_code::sc_expectation_failed: return stm << "sc_expectation_failed";
			case status_code::sc_im_a_teapot: return stm << "sc_im_a_teapot";
			case status_code::sc_misdirected_request: return stm << "sc_misdirected_request";
			case status_code::sc_unprocessable_entity: return stm << "sc_unprocessable_entity";
			case status_code::sc_locked: return stm << "sc_locked";
			case status_code::sc_failed_dependency: return stm << "sc_failed_dependency";
			case status_code::sc_too_early: return stm << "sc_too_early";
			case status_code::sc_upgrade_required: return stm << "sc_upgrade_required";
			case status_code::sc_precondition_required: return stm << "sc_precondition_required";
			case status_code::sc_too_many_requests: return stm << "sc_too_many_requests";
			case status_code::sc_request_header_fields_too_large: return stm << "sc_request_header_fields_too_large";
			case status_code::sc_unavailable_for_legal_reasons: return stm << "sc_unavailable_for_legal_reasons";
			case status_code::sc_internal_server_error: return stm << "sc_internal_server_error";
			case status_code::sc_not_implemented: return stm << "sc_not_implemented";
			case status_code::sc_bad_gateway: return stm << "sc_bad_gateway";
			case status_code::sc_service_unavailable: return stm << "sc_service_unavailable";
			case status_code::sc_gateway_timeout: return stm << "sc_gateway_timeout";
			case status_code::sc_http_version_not_supported: return stm << "sc_http_version_not_supported";
			case status_code::sc_variant_also_negotiates: return stm << "sc_variant_also_negotiates";
			case status_code::sc_insufficient_storage: return stm << "sc_insufficient_storage";
			case status_code::sc_loop_detected: return stm << "sc_loop_detected";
			case status_code::sc_not_extended: return stm << "sc_not_extended";
			case status_code::sc_network_authentication_required: return stm << "sc_network_authentication_required";
			default: return stm;
			}
	}
} // namespace http