# == Schema Information
#
# Table name: projects
#
#  id          :integer          not null, primary key
#  path        :string
#  name        :string
#  owner_id    :integer
#  description :text
#  created_at  :datetime         not null
#  updated_at  :datetime         not null
#

class Project < ActiveRecord::Base
end
