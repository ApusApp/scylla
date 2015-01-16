/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Copyright 2015 Cloudius Systems
 *
 * Modified by Cloudius Systems
 */

#ifndef CQL3_COLUMN_SPECIFICATION_HH
#define CQL3_COLUMN_SPECIFICATION_HH

#include "cql3/column_identifier.hh"
#include "db/marshal/reversed_type.hh"
#include "database.hh"

namespace cql3 {

class column_specification {
public:
    const sstring ks_name;
    const sstring cf_name;
    const ::shared_ptr<column_identifier> name;
    const ::shared_ptr<abstract_type> type;

    column_specification(sstring ks_name_, sstring cf_name_, ::shared_ptr<column_identifier> name_, ::shared_ptr<abstract_type> type_)
        : ks_name(ks_name_)
        , cf_name(cf_name_)
        , name(name_)
        , type(type_)
    { }

    /**
     * Returns a new <code>ColumnSpecification</code> for the same column but with the specified alias.
     *
     * @param alias the column alias
     * @return a new <code>ColumnSpecification</code> for the same column but with the specified alias.
     */
    ::shared_ptr<column_specification> with_alias(::shared_ptr<column_identifier> alias) {
        return ::make_shared<column_specification>(ks_name, cf_name, alias, type);
    }
    
    bool is_reversed_type() const {
        return ::dynamic_pointer_cast<db::marshal::reversed_type>(type) != nullptr;
    }
};

}

#endif
